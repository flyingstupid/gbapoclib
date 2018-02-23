#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Ancient pine trees shed their needles, creating a soft brown\n"+
      "blanket on the forest floor hiding much of the footpath. The \n"+
      "shoreline bends north and west of this small promintary. Both\n"+
      "north and west, the land again bends to the east and south \n"+
      "respectively, making much of the eastern coast visible.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for25", "north",
      FOREST_ROOMS+"for19", "west"
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
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n"
    }));
}
