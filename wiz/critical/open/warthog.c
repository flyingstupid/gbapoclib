inherit "inherit/monster";
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
 
  set_name("warthog");
  set_race("warthog");
  set_short("A wart hog");
  set_long("Una hoga negra de muy grandes colmillos y muy\n"+
           "subdesarrollada para cualquiera de su raza.\n");
  set_level(1);
  set_gender(random(2) + 1);
  set_aggressive(1);
  
 
  load_chat(10, ({ "hog squeaks at you.\n",
     "hog rumabges about, looking for food.\n",
     "hog looks up at you.\n",
     "hog nudges you with its nose.\n",
     "hog drinks some of the water from the ground.\n"
  }));
 
  load_a_chat(13, ({ "hog cries out in pain!\n",
     "hog bites at you.\n",
     "hog claws at you.\n",
     "hog nibbles at your toes.\n",
     "hog tries to run away, but fails.\n",
     "hog cries out for its friends.\n" 
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

