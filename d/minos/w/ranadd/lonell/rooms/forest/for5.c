#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Standing atop the cliffs of the island, the ocean stretches \n"+
      "out, vast and blue, to the south. The seeming endlessness of \n"+
      "it is breath taking. A short walk away is the easternmost \n"+
      "egde of the island. Only a few hearty trees grow along the \n"+
      "shore, giving a wide view of the surrounding area. A path\n"+
      "recedes into the forest to the north.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"

    );
    set_exits(({
      FOREST_ROOMS+"for11", "north",
      FOREST_ROOMS+"for6", "east",
      FOREST_ROOMS+"for4", "west"
    }));
    set_items(({
      "trees",
        "Tall trees populate the forest of Lonell.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "ocean",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
    }));
}
