#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A few small wild flowers have managed to grow amidst the \n"+
      "choking undergrowth. The vibrant purples and blues of the few\n"+
      "wild iris and cornflowers are a pleasant contrast to the \n"+
      "greens and browns of the living and dead trees and foliage. A\n"+
      "single cobblestone marks the wagon trail that must have been \n"+
      "a road through the forest. The path again turns, weaving its\n"+
      "way to the north and to the west.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_exits(({
      FOREST_ROOMS+"for14", "north",
      FOREST_ROOMS+"for7", "west"
    }));
    set_items(({
      "undergrowth#scrub#shrubbery",
        "Ground level plants spread out across the forest floor.\n",
      "flowers#iris#cornflowers",
        "Colorful flowers add contrast to the green and browns of the forest.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "trail",
        "A trail passes through the forest, mostly covered by leaves and branches.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
      "trees",
        "Tall trees populate the forest of Lonell.\n",
    }));
}
