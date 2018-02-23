#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Standing ageless and tall, a giant sycamore spreads its silvery boughs\n"+
      "like arms, reaching out to embrace the heavens. It overshadows the other\n"+
      "trees that grow in this part of the forest. Beyond the sycamore, to the\n"+
      "south, is a crossroads. Prickly thorn bushes grow all around the base of\n"+
      "the sycamore. The remains of a cobblestone path starts here, leading west,\n"+
      "while northward, animal tracks lead into a small grassy grove.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_day_desc(
    );
    set_night_desc(
    );
    set_exits(({
      FOREST_ROOMS+"for29", "north",
      FOREST_ROOMS+"for22", "west"
    }));
    set_items(({
      "sycamore",
        "A lone sycamore tree stands, spreading its branches, providing shade\n"+
        "on the cross roads.\n",
      "bough",
        "Thick arms of the trees of the forest. They stretch ever skyward.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "trees",
        "Tall trees populate the forest of Lonell.\n",
      "cross-roads#cross roads#crossroads#intersection",
        "A point where two trails meet.\n",
      "cobblestone#cobblestones",
        "Flat paving stones that once formed a network of roads on the island.\n",
      "thorn bushes#bushes",
        "A few thorn bushes grow along the ground around the base of a giant \n"+
        "sycamore tree.\n",
      "tracks#grove#grassy grove",
        "The paw prints of several wild animals lead north into a grassy grove.\n",
    }));
}
