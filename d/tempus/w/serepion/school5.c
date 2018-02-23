inherit "inherit/room2";

reset (arg) {
  reset_doors(0);
  if(arg) return;
  set_short("south hall");
  set_long("This is the southern hallway on the lower floor of the school.\n"+
     "A large set of stairs leads up to the second floor. The black carpet\n"+
     "stretches the length of the hall, coming to an end at the door at\n"+
     "the south end of the hall. The library is through the door.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"carpet", "A large carpet almost as wide as the hall.\n"+
     "It goes right up to the northern door.\n",
     "stairs", "A well worn set of oaken stairs leading up to the next floor.\n"}));
  set_exits(({"/d/tempus/w/serepion/school4.c", "north",
     "/d/tempus/w/serepion/school17.c", "up"}));
  load_door(({"file", "/d/tempus/w/serepion/school6",
     "direction", "south door", "closed",
     "long", "A small, wooden door that is seldom used.\n",}));
}
