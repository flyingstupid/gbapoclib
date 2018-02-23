#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A strong breeze, full of the tangy sea air, stirs the \n"+
      "branches of the many tall trees on the southwestern corner of\n"+
      "Lonell. Thick branches creek and crackle as they sway and \n"+
      "dance. From the southern to the western horizon, the great \n"+
      "sea stretches endless and blue. The remains of a wagon trail \n"+
      "bends to follow the shoreline.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
  set_smell("The tang of salt wafts on the breeze.\n");
  set_listen("Tree branches creek on the breeze.\n");
    set_exits(({
      FOREST_ROOMS+"for7",  "north",
      FOREST_ROOMS+"for2",  "east"
    }));
    set_items(({
      "branches",
        "Thick arms of the trees of the forest. They stretch ever skyward.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "trees",
        "Many tall trees populate the forest of Lonell.\n",
    "horizon",
    "The horizon is composed of two vast blue lines, one the sky, the other\n"+
    "the sea, melding together.\n",
      "sea",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "trail",
        "A trail passes through the forest, mostly covered by leaves and branches.\n" 
    }));
}

