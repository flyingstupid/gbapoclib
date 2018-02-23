/* wraith form */

inherit "inherit/timer";

status wraith(string targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(targ != "form") {
    notify_fail("wraith form?\n");
    return 0;
  }
  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level() 
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Wraith Form",
  "sphere",            alt_type, 
  "cost",              7,
  "damage",            time,
  "level",             7,
  "class", class,
  "cast time",         1,
  "spell object",      file,
  "passive",
  }));
  return 1;
}


/***************************************************************************/
/* when object cloned to target */

status cast_spell(object caster,object target,object prev,int level) {
  object wraith;

  if(wraith = present("wraith form 2", target)) {
    write("You extend the time of your wraithform spell.\n");
    wraith->adj_time(level * 60);
    destruct(this_object());
    return 1;
  }
  if(!target->query_ghost()) {
    write("Your body turns ghost like...\n");
    say(target->query_name() +"'s body becomes ghostlike...\n");
    target->toggle_ghost();
  }
  else {
    write("You are already dead..\n");
  }
  return 1;
} 


status drop(status quit) {
  if(quit) time_out();
  return 1;
}


void time_out() { 
  if(environment()->query_ghost()) {
    environment()->toggle_ghost();
  }
  ::time_out();
}

void dispel_magic() {  /* std spell fn to clean up */
  time_out();
}

status id(string str) {
  return str == "spell"
      || str == "wraith form";
}

void init() {
  add_action("dispel", "dispel");
  add_action("dispel", "Dispel");
  add_action("dispel", "end");
}

status dispel(string str) {
  if(str != "wraith form") return 0;
  time_out();
  return 1;
}

