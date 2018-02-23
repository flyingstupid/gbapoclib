/** Invisibilty **/

inherit "inherit/timer";


status invisibility(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "illusion";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level() 
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Invisibility",
  "sphere",            alt_type, 
  "cost",              8,
  "damage",            time,
  "level",             8,
  "class", class,
  "cast time",         1,
  "spell object",      file,
  "passive",
  "component",         "gem#gemstone#stone#rock",

/* other spell options... 
  "msg target",       0,
  "msg room",         0,
  "msg caster",       0,
 */
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int time) {
  object ob;

  ob = present("invisibility 2", caster);
  if(ob) {
    write("You extend the time of your invisibility spell.\n");
    ob->adj_time(time*30);
    destruct(this_object());
  }
  else {
    caster->set_invis(time);
    adj_time(time*45);
    write("You suddenly disappear.\n");

    say((string)caster->query_name()+" "+(string)caster->query_mmsgout()+"\n");
  }
  return 1;
}

void extra_long() {
  if(this_player() == environment())
    write("You are invisible.\n");
  else 
    write(environment()->query_name()+" is invisible.\n");
}

void time_out() {
  environment()->set_invis(0);
  environment()->save_character();
  ::time_out();
}


status drop(status quit) {
  if(quit) time_out();
  return 1;
}


void dispel_magic() { time_out(); }


status id(string str) { 
  return str == "spell"
      || str == "invisibility";
}

