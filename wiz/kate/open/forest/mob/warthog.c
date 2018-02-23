inherit "inherit/monster";
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
 
  set_name("Warthog");
  set_race("Warthog");
  set_short("A Warthog");
  set_long("Una Warthoga negra de muy grandes colmillos y muy\n"+
           "subdesarrollada para cualquiera de su raza.\n");
  set_level(1);
  set_gender(random(2) + 1);
  set_aggressive(1);
  
 
  load_chat(10, ({ "Warthog squeaks at you.\n",
     "Warthog rumabges about, looking for food.\n",
     "Warthog looks up at you.\n",
     "Warthog nudges you with its nose.\n",
     "Warthog drinks some of the water from the ground.\n"
  }));
 
  load_a_chat(13, ({ "Warthog cries out in pain!\n",
     "Warthog bites at you.\n",
     "Warthog claws at you.\n",
     "Warthog nibbles at your toes.\n",
     "Warthog tries to run away, but fails.\n",
     "Warthog cries out for its friends.\n" 
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

