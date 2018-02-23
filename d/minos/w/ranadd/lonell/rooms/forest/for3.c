#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A long set of wooden stairs leads down the cliff face to the \n"+
      "docks below. At the top of the stairs is the forest of Lonell. \n"+
      "Tall trees crowd together, their branches reaching ever skyward \n"+
      "while a blanket of fallen leaves and branches covers the ground \n"+
      "everywhere, all but hiding the path that leads off to the west.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_exits(({
      FOREST_ROOMS+"for2", "west"
    }));
  set_smell("The tang of salt wafts on the breeze.\n");
  set_listen("Tree branches creek on the breeze.\n");
    set_items(({
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "branches",
        "Thick arms of the trees of the forest. They stretch ever skyward.\n",
      "stairs",
        "A long wooden staircase of ironwood has been built into the cliffs, leading\n"+
        "between the docks and the forest of the island.\n",
      "docks",
        "A dock provides a landing point for ships to drop off passeners. A long\n"+
        "wooden staircase leads from the top of the dock up the cliffs.\n",
      "trees",
        "Many tall trees populate the forest of Lonell.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "leaves",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "blanket",
        "A layer of foliage covers the ground in a natural blanket.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
    }));
}


