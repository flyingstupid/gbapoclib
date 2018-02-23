inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("In the wall");
  set_long("You are inside the wall of the house. The wall continues\n"+
     "to the east and west into darkness.\n");
  set_weather(0, 1, 0);
  set_exits(({"/d/tempus/w/serepion/wall5.c", "east",
     "/d/tempus/w/serepion/wall3.c", "west"}));
  set_listen("You hear the sounds of mice all around you.\n");
}
