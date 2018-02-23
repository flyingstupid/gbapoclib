#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a open grassy plain");

  set_long(
  "A large open, dry and grassy plain extends in all directions.\n"+
  "The tall barren and icy peaks of Darken Mountain loom ever\n"+
  "closer to the far north. There is a single large tree to the west.\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"plain5", "south",
	PATH+"plain10", "north",
	PATH+"plain3", "east",
	PATH+"big_tree", "west",
  }));

  set_items(({
	"tree",
	"A large gnarled old tree to the west",

	"ruins#homestead",
	"It looks like it has been deserted for some time",

	"darken mountain#mountain",
	"Darken Mountain, home to the drow, is northward",

        "grass#grassy plain#plain",
        "Dry grass as tall as a halfling extends across a wide open plain",

        "cloud#clouds",
        "They are fluffy clouds. One looks like a duck\n",
  }));


  set_listen("You hear the wind blowing in the tall grass\n");
}                                 
