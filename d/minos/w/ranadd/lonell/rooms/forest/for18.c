#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A footpath leads down the cliff face to a quaint inlet. Soft \n"+
      "grass, nearly a foot high, sways in the gentle sea breeze. \n"+
      "Pines grow in the cliffs that rise twenty feet high west of \n"+
      "the inlet, and to the east, the ocean lays a mere five feet \n"+
      "below the edge of the land.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell("The tang of salt water wafts on the breeze.\n");
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for19", "east",
      FOREST_ROOMS+"for12", "south",
      FOREST_ROOMS+"for17", "west"
    }));
    set_items(({
      "pine#pines#pine trees",
        "Stately firs, they leave their needles on the ground creating a soft\n"+
        "blanket.\n",
      "ocean",
        "Vast and blue, it stretches to the horizon and beyond.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "path#footpath",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
      "inlet",
        "A grassy inlet lays at the bottom of a footpath which leads down the\n"+
        "cliff face.\n",
      "grass",
        "Tall grasses sway in the breeze as gentle as waves on an ocean.\n",
    }));
}
