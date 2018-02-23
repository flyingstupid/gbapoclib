#include <mudlib.h>
#include <ranadd.h>

inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Sounds of waves crashing on the cliff face below fill the \n"+
      "air. A faint breeze of salt air drifts in from the west. A \n"+
      "fallen tree lays to the north, rotted to the state of being \n"+
      "not much more than a shell of its once mighty girth. The path \n"+
      "has widened from the east, and shows faint signs that wagons \n"+
      "once frequented it. The ruts from many wagon wheels grow \n"+
      "deeper as they move westward.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
  set_smell("The tang of salt wafts on the breeze.\n");
  set_listen("Tree branches creek on the breeze.\n");
    set_exits(({
      FOREST_ROOMS+"for3", "east",
      FOREST_ROOMS+"for1", "west"
    }));
    set_items(({
      "ruts",
        "Permanent indentations in the earth mark the one-time trade route.\n",
      "tree",
        "Once a tree of great size, the husk is all that now remains of the great\n"+
        "oak.\n",
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
    }));
}
