/** Shield **/


#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status shield(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "abjuration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Shield",
  "sphere",            alt_type, 
  "cost",              2,
  "damage",            time,
  "level",             3, /* 3 shield - 4 cast time + 4 no component */
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",      "The air starts to waver in front of you.\n",
  "casting msg room", "The air starts to waver in front of "+ NAME +".\n",
  "passive",

/* other spell options... 
  "immune",           0,
  "msg target",       0,
  "msg room",         0,
  "msg caster",       0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int time) {
  object shield;

  shield = present("shield spell", target);
  if(shield) {
    tell_object(target,"You extend the time of your shield spell.\n");
    shield->adj_time((time*30)+60);
  }
  else {
    tell_object(target,"You see a shield of vibrating force appear in front "+
                       "of you.\n");
    say("You see a shield of vibrating force appear in front of "+
        (string)target->query_name() +".\n", target);
    shield = clone_object("obj/skills/sp_arm");
    shield->set_name("shield");
    shield->set_alias("shield spell");
    shield->set_long("The shield vibrates in front of you.\n");
    shield->set_extra_long("There is a vibrating shield of force in front "+
                           "of "+(string)target->query_name()+".\n");
    shield->set_alt_extra_long("There is a vibrating shield of force in front"+
                               " of you.\n");
    shield->set_listen("You hear the air hum from the vibration of the "+
                       "shield.\n");
    shield->set_info("The shield was created by a shield spell.\n"+
                     "It has only @@query_approx_time:"+file_name(shield)+
                     "@@ left before it expires.\n");
    shield->set_ac_bonus(1);
    move_object(shield, target);
    shield->adj_time((time*30)+60);
  }
  target->recalc_ac();
  destruct(this_object());
  return 1;
}

status id(string str) {  return str == "spell"; }

