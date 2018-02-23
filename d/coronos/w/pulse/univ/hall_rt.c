/******************************************************************************
 * hall_rt.c
 * Right Hallway for Mage University
 * 
 * Pulse
 * October, 1996
 */
 
#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
  if (arg) {
    return;
  }
  
  ::reset();
  
  load_door((  {
        "destination", "/d/coronos/w/solstice/univ/archway",
        "direction",   "west door",
        "long",        "A solid oak door with an ornately carven steel handle\n"+
                       "with the insignia of the school prominently carved in\n"+
                       "middle.\n",
  } ));
  
  set_long(
    "Inside the university, the ceiling towers some twenty feet over the\n"+
    "ground, probably to minimize the damage a rogue apprentice can do.  The\n"+
    "interior has that feeling of having been around forever.  There is a\n"+
    "natural respect by the students and faculty towards this building, as\n"+
    "is often exhibited towards the venerable, even buildings.\n"
  );
 
  set_items(( {
    "floor#ground",
    "There are the beginnings of tread imprints in the floor, from continuous\n"+
    "use.  It is made out of the same stone as the road outside, but\n"+
    "appears to be much older.\n"
  }));
  
  set_listen("The scuffling of feet and the murmur of effusive voices deter\n"+
	     "silence from ever entering this building.\n");
  
  set_smell("This hallway has the musky smell all old buildings by default\n"+
	    "inherit after a certain period of time.\n");
  
  set_exits(( {
    "/d/coronos/w/solstice/univ/charm", "east"
  } ));
}
