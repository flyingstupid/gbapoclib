#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Rocks of assorted sizes lay strewn across the barren ground \n"+
      "which falls abruptly into the great ocean to the south and \n"+
      "east. Crashing loudly, waves beat the tall cliffs that encase\n"+
      "the island. Stretching to the northwest is a dense forest, \n"+
      "while the shore line can be followed along its outer edges,\n"+
      "north and west.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_listen("The crash of mighty waves against solid cliffs is deafening.\n"); 
    set_exits(({
      FOREST_ROOMS+"for12", "north",
      FOREST_ROOMS+"for5", "west"
    }));
    set_items(({
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "ocean",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "waves",
        "White crested waves roll across the surface of the great ocean.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "rocks",
        "The ground is covered with rocks that range in size from a robin's egg to\n"+
        "the size of a man's body.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
    }));
}
