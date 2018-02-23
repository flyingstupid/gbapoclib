#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Off to the west, a long line of pine trees grows along the\n"+
      "boundary between the forest and the swamp. A layer of needles\n"+
      "covers the ground all but hiding an old wagon trail which \n"+
      "leads north, south and west. The coast line stretches off \n"+
      "eastward for quite some way.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for35", "north",
      FOREST_ROOMS+"for25", "south",
      FOREST_ROOMS+"for31", "west"
    }));
    set_items(({
      "pine#pines#pine trees#fir#fir trees#barrior",
        "Stately firs grow trunk to trunk leaving their needles on the ground,\n"+
        "creating a soft blanket.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "ruts#groves#wagon trail#trail",
        "Permanent indentations in the earth mark the one-time trade route.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
    }));
}
