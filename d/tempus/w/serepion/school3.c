inherit "inherit/room2";

reset (arg) {
  load_door(({"file", "/d/tempus/w/serepion/school2",
     "direction", "north door", 
     "long", "A large oak door engraved with ivy.\n",}));
  if(arg) return;
  set_short("north hall");
  set_long("This is the northern hallway on the lower floor of the school.\n"+
     "A large set of stair lead up to the second floor. The black carpet\n"+
     "stretches the length of the hall, coming to an end at a door at\n"+
     "the north end of the hall.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"carpet", "A large carpet almost as wide as the hall.\n"+
     "It goes right up to the northern door.\n",
     "stairs", "A well worn set of oaken stairs leading up to the next floor.\n"}));
  set_exits(({"/d/tempus/w/serepion/school4.c", "south",
     "/d/tempus/w/serepion/school17.c", "up"}));
}
