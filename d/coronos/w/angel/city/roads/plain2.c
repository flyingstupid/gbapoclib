#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a open grassy plain");

  set_long(
  "A large open, dry and grassy plain extends in all directions.\n"+
  "You can see a dirt trail far away to the south. The tall barren\n"+
  "and icy peaks of Darken Mountain loom to the north\n");

  set_weather(1,0,0);

  set_exits(({
        PATH+"plain1", "south",
	PATH+"plain3", "north",
	PATH+"plain4", "east",
	PATH+"plain5", "west",
  }));

  set_items(({
	"darken mountain#mountain",
	"Darken Mountain, home to the drow, is northward",

        "grass#grassy plain#plain",
        "Dry grass as tall as a halfling extends across a wide open plain",

        "cloud#clouds",
        "They are fluffy clouds. One looks like a wombat\n",
  }));


  set_listen("You hear wind blowing in the tall grass\n");
}                                 
