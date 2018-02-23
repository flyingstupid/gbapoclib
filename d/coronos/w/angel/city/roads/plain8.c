#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a open grassy plain");

  set_long(
  "A large open, dry and grassy plain extends in all directions.\n"+
  "The tall barren and icy peaks of Darken Mountain loom ever\n"+
  "closer to the far north. The ruins of an old building stand\n"+
  "to the south.\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"plain13", "north",
	PATH+"plain6", "west",
	PATH+"ruin", "south",
  }));

  set_items(({
	"ruins#homestead",
	"It looks like it has been deserted for some time",

	"darken mountain#mountain",
	"Darken Mountain, home to the drow, is northward",

        "grass#grassy plain#plain",
        "Dry grass as tall as a halfling extends across a wide open plain",

        "cloud#clouds",
        "They are fluffy clouds. One looks like a dragonfly\n",
  }));


  set_listen("You hear the wind blowing in the tall grass\n");
}                                 
