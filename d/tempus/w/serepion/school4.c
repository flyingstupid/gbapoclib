inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("main hall");
  set_long("This is the central hall of the enormous school. In the center\n"+
     "of this intersection of halls is a large pillar. The black carpet\n"+
     "stretches off in all directions. It looks like the dining hall is\n"+
     "to the north, and the entrance is to the south.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"carpet", "A large, black carpet almost as wide as the hall,"+
     " extending into the school.\n",
     "pictures", "All of the pictures are well taken care of, but many of"+
     " the presidents weren't.\n Some are missing parts of ears, have"+
     " scars, or are wearing eyepatches.\n"}));
  set_exits(({"/d/tempus/w/serepion/school3.c", "north",
     "/d/tempus/w/serepion/school9.c", "east",
     "/d/tempus/w/serepion/school5.c", "south",
     "/d/tempus/w/serepion/school1.c", "west"}));
}
