#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a open grassy plain");

  set_long(
  "A large open, dry and grassy plain extends in all directions.\n"+
  "The tall barren and icy peaks of Darken Mountain loom ever\n"+
  "closer to the far north. A single tree, blackened by a lightning\n"+
  "strike many years ago, stands alone on the plain.\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"plain7",     "east",
	PATH+"giant_path", "west",
  }));

  set_items(({
	"tree",
	"It stands nearly 40 feet tall. The only branches are 30 feet up",

	"branches",
	"They are too high to reach",

	"darken mountain#mountain",
	"Darken Mountain, home to the drow, is northward",

        "grass#grassy plain#plain",
        "Dry grass as tall as a halfling extends across a wide open plain",

        "cloud#clouds",
        "They are fluffy clouds. One looks like an elf\n",
  }));


  set_listen("You hear the wind blowing in the tall grass\n");
}                                 
