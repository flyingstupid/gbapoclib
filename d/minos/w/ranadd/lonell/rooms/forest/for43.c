#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Thick undergrowth competes with a dense copse of trees for a \n"+
      "shaky foothold in the life giving, yet rocky soil. Gnarled \n"+
      "roots creep along the ground, ready to trip the unwary. Tall\n"+
      "pines and oaks grow tightly together, making travel \n"+
      "impossible in all directions, except back to the south.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_exits(({
      FOREST_ROOMS+"for38", "south"
    }));
    set_items(({
      "copse",
        "A thick cluster of trees.\n",
      "trees",
        "Tall trees populate the forest of Lonell.\n",
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
    }));
}
