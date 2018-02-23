inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("Base of the wall");
  set_long("This is part of the crawlspace directly underneith the wall "+
     "of the house.\n");
  set_weather(0, 1, 0);
  set_exits(({"/d/tempus/w/serepion/floor5.c", "east",
     "/d/tempus/w/serepion/floor7.c", "west"}));
  set_listen("You hear the sounds of mice all around you.\n");
}
