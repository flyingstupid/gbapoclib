#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Spray from the waves that are crashing against the cliffs to \n"+
      "the west fills the air with the salty tang of sea water. Dead \n"+
      "leaves and branches litter the ground. No one has seen to the \n"+
      "maintenance of the paths of Lonell for quite some time, and \n"+
      "this makes travel difficult at times. The once well-used \n"+
      "wagon path follows the shoreline to the south, and turns east\n"+
      "toward the center of the forest.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
  set_smell("The tang of salt water wafts on the breeze.\n");
  set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for8", "east",
      FOREST_ROOMS+"for1", "south"
    }));
    set_items(({
      "waves",
        "White crested waves roll across the surface of the great ocean.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "leaves#leaves and branches#branches#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
    }));
}
