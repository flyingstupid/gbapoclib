#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "High cliffs rise up out of the foam of crashing waves which\n"+
      "stop as they are confronted by the towering cliffs. The land\n"+
      "itself begins to slope downward to the north. Ancient pine \n"+
      "trees grow right to the edge of the cliff face, and have left\n"+
      "a soft bed of needles on the rocky soil. The coast line \n"+
      "extends southward, while to the north lies a small inlet.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for18", "north",
      FOREST_ROOMS+"for6", "south"
    }));
    set_items(({
      "pine#pines#pine trees",
        "Stately firs, they leave their needles on the ground creaspting a soft\n"+
        "blanket.\n",
      "coast#coastline#coast line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "needles",
        "A layer of soft brown pine needles covers the forest floor.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "waves",
        "White crested waves roll across the surface of the great ocean.\n"
      "inlet",
        "A grassy inlet lays at the bottom of a footpath which leads down the\n"+
        "cliff face.\n",
    }));
}
