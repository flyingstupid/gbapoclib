inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("Base of the wall");
  set_long("You come to a bend in the crawlspace, with the bottom of the\n"+
     "wall right above you. You notice a large hole in the wood, which\n"+
     "would allow you to get up inside the wall.\n");
  set_weather(0, 1, 0);
  set_exits(({"/d/tempus/w/serepion/floor4.c", "south",
     "/d/tempus/w/serepion/floor6.c", "west",
     "/d/tempus/w/serepion/wall3.c", "up"}));
  set_listen("You hear the sounds of mice all around you.\n");
}
