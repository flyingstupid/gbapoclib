#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A footpath leads along the eastern shore of the island. \n"+
      "Ancient pines shed their needles, leaving a soft carpet on \n"+
      "the ground. The trail dips to the west, leading down the side\n"+
      "of the cliffs to a quaint inlet, beyond that, to the \n"+
      "southwest is a dense forest. And to the northwest, stretches \n"+
      "the stagnant swamp that covers much of the interior of the\n"+
      "island.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for20", "east",
      FOREST_ROOMS+"for18", "west"
    }));
    set_items(({
      "pine#pines#pine trees",
        "Stately firs, they leave their needles on the ground creating a soft\n"+
        "blanket.\n",
      "path#footpath#trail",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
      "needles",
        "A layer of soft brown pine needles covers the forest floor.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n"
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "inlet",
        "A grassy inlet lays at the bottom of a footpath which leads down the\n"+
        "cliff face.\n",
    }));
}
