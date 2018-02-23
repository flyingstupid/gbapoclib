/* enlarge */

inherit "inherit/timer";

int carry_bonus, wc_bonus;

status enlarge(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "alteration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()  /* wands */
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Enlarge",
//"component",  "dragon head#giant head",
  "sphere",            alt_type, 
  "cost",              12,
  "damage",            time,
  "level",             12,
  "class", class,
  "cast time",         5,
  "passive",
  "spell object",      file,
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int time) {
  object enlarge;

  enlarge = present("strength 2", target);
  if(enlarge) {
    write("You extend the time of your Enlarge Spell.\n");
    enlarge->adj_time(time * 60);
    destruct(this_object());
    return 1;
  }
  tell_object(target,
    "You feel your muscles buldge and stretch as you grow taller...\n");
  if(target != caster) {
    tell_object(caster,"You cast a enlarge spell on "+ target->query_name() 
                      +".\n");
  }
  say(caster->query_name() +" casts a spell on "+ target->query_name() +".\n"+
      target->query_name() +" looks quite large now!\n");
  carry_bonus = time/5;
  /* not quite as good as strength spell! */
  wc_bonus = time/5;

  if(carry_bonus > 40) carry_bonus = 40;
  if(wc_bonus > 5) wc_bonus = 5;
  adj_time(time * 60);
  target->recalc_carry();
  return 1; 
} 


status id(string str) {
  return str == "spell"
      || str == "enlarge"
      || str == "external";
}

int carry_bonus() { return carry_bonus; }
int weapon_class_bonus() { return wc_bonus; }

void time_out() {
  carry_bonus = 0;
  tell_object(environment(), "You grow back to your normal size.\n");
  environment()->recalc_carry();
  ::time_out();
}

void dispel_magic() {  time_out(); }

status drop(status quit) {
  if(quit) time_out();
  return 1;
}
