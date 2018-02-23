#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Thick brown tree trunks stand everywhere in this heavily over \n"+
      "grown section of the forest. The ground is littered with \n"+
      "gnarled roots which creep along. Tall pines and oaks crowd \n"+
      "tightly together, struggling with each other, and with the \n"+
      "scrub for room. From the northeast, a loud roaring sound\n"+
      "eminates.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_listen("The crashing of waves against the cliffs below barely masks a\n"+
      "thunderous roaring from somewhere to the northeast.\n");
    set_exits(({
      FOREST_ROOMS+"for45", "east",
      FOREST_ROOMS+"for39", "south"
    }));
    set_items(({
      "undergrowth#scrub#shrubbery",
        "Ground level plants spread out across the forest floor.\n",
      "roots",
        "The roots of the trees break through the ground, creeping along its\n"+
        "surface.\n",
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "pine#pines#pine trees#fir#fir trees",
        "Stately firs, they leave their needles on the ground creating a soft\n"+
        "blanket.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
    }));
}
