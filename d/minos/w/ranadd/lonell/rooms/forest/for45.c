#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The oaks and pines of this dense grove have littered the forest floor with \n"+
      "fallen sticks and leaves. High cliffs seperate the land from the rolling \n"+
      "ocean far below. A great roaring sound eminates from the north. Although\n"+
      "it is very loud, and therefore close at hand, the numerous tree trunks \n"+
      "and branches prevent peering northward for the source.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for49", "north",
      FOREST_ROOMS+"for44", "west"
    }));
    set_items(({
      "undergrowth#scrub#shrubbery",
        "Ground level plants spread out across the forest floor.\n",
      "oak#oaks#oak trees",
        "Many oak trees fill the forest, droppng their acorns on the forest floor.\n",
      "pine#pines#pine trees#fir#fir trees",
        "Stately firs, they leave their needles on the ground creating a soft\n"+
        "blanket.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "leaves#sticks and leaves#sticks#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "ocean",
        "Vast and blue, it stretches to the horizon and beyond.\n",
    }));
}
