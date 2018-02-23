#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Soft needles of many fir trees litter the ground, creating a \n"+
      "thick blanket. Waves break against the cliffs below, their \n"+
      "white spray flys high into the air, filling it with the tang\n"+
      "of salt water. Shallow grooves under the pine needles mark an\n"+
      "old wagon trail leading north and west.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for32", "north",
      FOREST_ROOMS+"for20", "south",
      FOREST_ROOMS+"for24", "west"
    }));
    set_items(({
      "pine#pines#pine trees#fir#fir trees#barrior",
        "Stately firs grow trunk to trunk leaving their needles on the ground,\n"+
        "creating a soft blanket.\n",
      "needles",
        "A layer of soft brown pine needles covers the forest floor.\n",
      "blanket",
        "A layer of foliage covers the ground in a natural blanket.\n",
      "waves",
        "White crested waves roll across the surface of the great ocean.\n",
      "ruts#groves",
        "Permanent indentations in the earth mark the one-time trade route.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
    }));
}
