/* anti-magic shell */

inherit "inherit/timer";

status anti(string spell_type, mixed alt_type, string class) {
  int i, time;
  string file;

  if(spell_type != "magic shell") {
    notify_fail("anti magic shell?\n");
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
  "target",            environment(this_player()),
  "name",              "Anti Magic Shell",
  "sphere",            alt_type, 
  "cost",              20,
  "level",             20,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "damage",            time,
  "casting msg",       "You feel magic leave the area.\n",
  "casting msg room",  "You feel an absence of magic....\n",
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  tell_room(target, "The air shimmers about you.\n");
  adj_time(dmg * 20);
  return 1;
}  

void time_out() {
  tell_object(environment(),"The Anti-magic shell fades...\n");
  ::time_out();
}

void extra_long() {
  write("The air is shimmering. Yet, you feel an absence.\n"+
        "An absence of something supernatural.\n");
}

status id(string str) {
  return str == "spell"
      || str == "Nulmagic"
      || str == "anti magic shell";
}


