/* enhance strength */

inherit "inherit/timer";

int carry_bonus;

status booststr(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "enhancing";
  if(!class) class = "medic";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()  /* wands */
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Boost Strength",
  "sphere",            alt_type, 
  "cost",              0,
  "damage",            time,
  "level",             5,
  "class", class,
  "cast time",         1,
  "passive",
  "spell object",      file,
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int time) {
  object strength;

  strength = present("strength 2", target);
  if(strength) {
    write("You extend the time of your strength serum.\n");
    strength->adj_time(time * 60);
    destruct(this_object());
    return 1;
  }
  tell_object(target,"You feel a tingling shoot through your body...\n");
  if(target != caster) {
    tell_object(caster,"You inject "+ target->query_name() 
                      +" with strengthing serum.\n");
  }
  say(caster->query_name() +" injects something into "+ target->query_name() +".\n"+
      target->query_name() +" looks quite strong now.\n");
  carry_bonus = time/2;

  if(carry_bonus > 40) carry_bonus = 40;
  adj_time(time * 60);
  target->recalc_carry();
  return 1; 
} 


status id(string str) {
  return str == "spell"
      || str == "strength"
      || str == "external";
}

int carry_bonus() { return carry_bonus; }

void time_out() {
  carry_bonus = 0;
  tell_object(environment(),"Your strength weakens...\n");
  environment()->recalc_carry();
  ::time_out();
}

void dispel_magic() {  time_out(); }

status drop(status quit) {
  if(quit) time_out();
  return 1;
}
