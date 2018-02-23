#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A long wooden dock can be seen stretching into the ocean to the\n"+
      "southwest. Sea birds fill the air, squaking as they dive into \n"+
      "the surf, then they fly straight at the cliffs that rise up \n"+
      "from the ocean as they probably return to their nests. Fewer \n"+
      "trees grow along the shore, making it possible to see the \n"+
      "eastern shore, a short distance off.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_listen("The air is filled with the sounds of many birds.\n");

    set_exits(({
      FOREST_ROOMS+"for10", "north",
      FOREST_ROOMS+"for5", "east"
    }));
    set_items(({
      "trees",
        "Many tall trees populate the forest of Lonell.\n",
      "docks#dock",
        "A dock provides a landing point for ships to drop off passeners. A long\n"+
        "wooden staircase leads from the top of the dock up the cliffs.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "ocean",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
    }));
}
