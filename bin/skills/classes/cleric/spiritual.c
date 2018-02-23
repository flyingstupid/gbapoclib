/* Spiritual Hammer */  

inherit "inherit/weapon";
inherit "inherit/timer";

#define NAME "@@query_name:$this_player()$@@"

status spiritual(string targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(targ != "hammer") {
    notify_fail("spiritual hammer?\n");
    return 0;
  }

  if(!alt_type) alt_type = "combat_sphere";
  if(!class) class = "cleric";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level() /* wands */
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Spiritual Hammer",
  "sphere",            alt_type, 
  "cost",              4,
  "damage",            time, /* a time component */
  "level",             4,
  "class", class,
  "spell object",      file,
  "cast time",         2,
  "casting msg",       "Before your eyes a war hammer appears.\n",
  "casting msg room",  "A war hammer appears before "+NAME+".\n",
  "passive",
  }));
  return 1;
}

/***********************************************************************/
/* when cloned */

void time_out() {
  tell_object(environment(),"Your Spiritual Hammer fades into nothingness.\n");
  ::time_out();
}

void dispel_magic() { time_out(); }


status cast_spell(object caster,object target,object prev,int dmg) {
  object hammer;

  hammer = present("spiritual hammer", target);
  if(hammer) {
      write("You extend the time of the Spiritual Hammer spell.\n");
      hammer->adj_time(dmg * 60);
      destruct(this_object());
      return 1;
  }
  tell_object(target, "The hammer floats into your hands.\n");
  set_name("war hammer");
  set_alias("hammer");
  set_alt_name("spiritual hammer");
  set_type("crush");
  set_wc(12);
  set_length(24);
  set_weight(5);
  set_value(0);
  set_short("A spiritual hammer");
  set_long("It is a force of magical energy vaguely shaped like a "+
          "war hammer.\n");
  set_info("The Spiritual Hammer has "+
           "@@query_approx_time:"+file_name(this_object())+":@@ left before "+
           "it vanishes.\n");
  adj_time(dmg * 60);
  return 1;
}

status id(string str) {
  return str == "spell"
      || ::id(str);
}


status drop(status quit) {
  if(quit) time_out();
  return 1;
}

