inherit "inherit/monster";
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
 
  set_name("ripper_robot");
  set_race("robot");
  set_short("a Ripper Robot");
  set_long("A small robot with one pincher arm that ends in a c-clamp\n"+
  " and one wielding arm set on a track base.\n");
  set_level(random(2)+3);
  set_gender(0);
  set_aggressive(1);
 
 /*
  load_chat(10, ({ "Wolf growls at you.\n",
     "Wolf rumabges about, looking for food.\n",
     "Wolf looks up at you.\n",
  }));
 */
  load_a_chat(13, ({ "The Ripper Robot beeps mencing!\n",
     
  }));
 
  set_attack_msg(({
     "burns",       "horribly with its welder",
     "crushed",     "with it's pincher claw",
     "whack",       "with it's pincher claw",
     "chomped",     "with it's pincher claw",
     "chewed",      "with it's pincher claw",
     "grazed",      "with its welder"
  }));
}

void monster_died() {
  tell_room(environment(),"The Ripper Bot suddenly stops moving and then EXPLODES!");
}