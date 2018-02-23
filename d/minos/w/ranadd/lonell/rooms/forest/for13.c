#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Along the western shore, a pleasantly warm breeze carries the\n"+
      "salty sea air inland. Oak trees, of various sizes grow right \n"+
      "to the edge of the coastline. Near a crossroads to the east,\n"+
      "stands an ancient Sycamore. Another crossroads lays to the\n"+ 
    "north, however thick growth prevents passage that way.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
 /* blocked off until later
      FOREST_ROOMS+"for22", "north",
 */
      FOREST_ROOMS+"for14", "east"
    }));
    set_items(({
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n"
      "sycamore#Sycamore",
        "A lone sycamore tree stands, spreading its branches, providing shade\n"+
        "on the cross roads.\n",
      "cross-roads#cross roads#crossroads#intersection",
        "A point where two trails meet.\n",
    }));
}
