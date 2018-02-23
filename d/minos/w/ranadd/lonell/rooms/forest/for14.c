#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The path has reached an intersection. A few cobblestones \n"+
      "trail off to the east and west, while to the south, there \n"+
      "seem to be none. North of the trail, stands an ancient \n"+
      "sycamore, its white bark appears almost silver. It has \n"+
      "provided a pleasantly shaded spot for travelers to rest along\n"+
      "the cross-roads for a very long time.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_exits(({
      FOREST_ROOMS+"for15", "east",
      FOREST_ROOMS+"for8", "south",
      FOREST_ROOMS+"for13", "west"
    }));
    set_items(({
      "sycamore",
        "A lone sycamore tree stands, spreading its branches, providing shade\n"+
        "on the cross roads.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
      "trail",
        "A trail passes through the forest, mostly covered by leaves and branches.\n",
      "cross-roads#cross roads#crossroads#intersection",
        "A point where two trails meet.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
    }));
}
