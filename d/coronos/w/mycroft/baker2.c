/* main_st5.c */

inherit "inherit/room2";

reset(arg) {

  if(arg) return;

set_short("The 200 Block of Baker street");
  set_long(
"\tBaker Street\n"+
"You stand on Baker street.  To the east lies the main entrance to\n"+
"the governmental annex.  To the south is the imposing bulk of t\n"+      
"annex itself. To the North lies a path up to a mansion of a wealthy\n"+
"bureacrat who works across the street.\n");
	
  set_night_desc(
"Street lights flicker, genlty lighting the path through this upscale\n"+
"neighborhood.\n");


  set_items(({
"mansion#mansion",
"It is a large baroque-style mansion.",



  }));

  set_smell("The fragrent smells of new flowers comes from the north.\n");



  set_weather(2, 1, 0);
  set_exits(({
"d/coronos/w/mycroft/baker1.c","west",
"d/coronos/w/mycroft/baker3.c","east",
  }));
}

