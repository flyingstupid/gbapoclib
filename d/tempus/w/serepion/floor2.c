inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("Space under the floorboards");
  set_long("You are in a crawlspace underneath the floorboards of the\n"+
     "old woman's house.\n");
  set_weather(0, 1, 0);
  set_exits(({"/d/tempus/w/serepion/floor3.c", "north",
     "/d/tempus/w/serepion/floor1.c", "south"}));
  set_listen("You hear the sounds of mice all around you.\n");
}
