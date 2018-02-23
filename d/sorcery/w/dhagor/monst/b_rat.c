inherit "inherit/monster";
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
 
  set_name("rat");
  set_race("rat");
  set_short("A black rat");
  set_long("Una rata negra de muy grandes colmillos y muy\n"+
           "subdesarrollada para cualquiera de su raza.\n");
  set_level(1);
  set_hp(40 + random(15));
  set_ac(3);
  set_gender(random(2) + 1);
  set_wc(5);
  set_aggressive(1);
  add_money(10 + random(10));
 
  load_chat(10, ({ "Rat squeaks at you.\n",
     "Rat rumabges about, looking for food.\n",
     "Rat looks up at you.\n",
     "Rat nudges you with its nose.\n",
     "Rat drinks some of the water from the ground.\n"
  }));
 
  load_a_chat(13, ({ "Rat cries out in pain!\n",
     "Rat bites at you.\n",
     "Rat claws at you.\n",
     "Rat nibbles at your toes.\n",
     "Rat tries to run away, but fails.\n",
     "Rat cries out for its friends.\n" 
  }));
 
  set_attack_msg(({
     "bit",         "deep at the throat",
     "bit",         "on the arm",
     "nibbled",     "on the leg",
     "chomped",     "on the ankle",
     "nibbled",     "on the toe",
     "nibbled",     "with it's teeth",
     "grazed",      "with its claws"
  }));
}
