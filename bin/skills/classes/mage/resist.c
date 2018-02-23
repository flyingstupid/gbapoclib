/* resist magic */

inherit "inherit/timer";

#define NAME "@@query_name:$this_player()$@@"

status resist(string spell_type, mixed alt_type, string class) {
  int i, time;
  string file;

  if(spell_type != "magic") {
    notify_fail("resist magic?\n");
    return 0;
  }

  if(!alt_type) alt_type = "abjuration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()
       : (int)call_other(this_player(),"query_"+ alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Resist Magic",
  "sphere",            alt_type, 
  "cost",              18,
  "level",             18,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "damage",            time,
  "casting msg",       "You start to feel resistant to magic.\n",
  "casting msg room",  "You see "+ NAME +" wave, and chant....\n",
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  object ob;

  if((ob = present("resist magic 2", target))) {
    tell_object(target,"You extend the time of your Resist Magic spell.\n");
    ob->adj_time(dmg * 20);
    destruct(this_object());
    return 1;
  }
  tell_object(target, "You feel resistant to magic.\n");
  target->set_magic_resist(dmg);
  adj_time(dmg * 20);
  return 1;
}  

void time_out() {
  tell_object(environment(),"Your magic resistance fades...\n");
  environment()->set_magic_resist(0);
  ::time_out();
}

status drop(status quit) {
  if(quit) time_out();
  return 1;
}

status id(string str) {
  return str == "spell"
      || str == "resist magic";
}

