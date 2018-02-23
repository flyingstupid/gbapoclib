inherit "inherit/monster";
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
 
  set_name("wolf");
  set_race("Wolf");
  set_short("A black Wolf");
  set_long("A large black wolf with hunger in his eyes"+
           "and blood on its coat. Its teeth are bared!\n");
  set_level(random(3)+1);
  set_gender(random(2) + 1);
  set_aggressive(1);
 
  load_chat(10, ({ "Wolf growls at you.\n",
     "Wolf rumabges about, looking for food.\n",
     "Wolf looks up at you.\n",
  }));
 
  load_a_chat(13, ({ "Wolf cries out in pain!\n",
     "Wolf bites at you.\n",
     "Wolf claws at you.\n",
     
  }));
 
  set_attack_msg(({
     "bit",         "deep at the throat",
     "bit",         "on the arm",
     "nibbled",     "on the leg",
     "chomped",     "on the ankle",
     "nibbled",     "with it's teeth",
     "grazed",      "with its claws"
  }));
}

