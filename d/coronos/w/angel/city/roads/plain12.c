#include <mudlib.h>
#include "paths.h"

inherit ROOM;

void reset(status arg) {

  if(arg) return;

  set_short("a open grassy plain");

  set_long(
  "A large open, dry and grassy plain extends in all directions.\n"+
  "The tall barren and icy peaks of Darken Mountain are very close\n");

  set_weather(1,0,0);

  set_exits(({
	PATH+"plain11", "east",
	PATH+"plain10", "south",
  }));

  set_items(({
	"darken mountain#mountain",
	"Darken Mountain, home to the drow, is a few miles north",

        "grass#grassy plain#plain",
        "Dry grass as tall as a halfling extends across a wide open plain",

        "cloud#clouds",
        "They are fluffy clouds. One looks like a dark elf\n",
  }));


  set_listen("You hear the wind blowing in the tall grass\n");
}                                 
