#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A small patch of solid ground stands surrounded on all sides,\n"+
      "save one, by the stagnant waters of the swamp. Only a narrow, \n"+
      "marshy path connects the small mound of earth with the forest\n"+
      "to the southeast. Poised at the center of the mound is a very\n"+
      "old willow tree. Its branches droop to the ground, creating a\n"+
      "lush green curtain. A bole has been hollowed out in the \n"+
      "willow. It is an ideal hiding place for small woodland \n"+
      "creatures.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_listen("The sound of crashing waves drifts thru the trees.\n");
    set_exits(({
      FOREST_ROOMS+"for35", "southeast"
    }));
    set_items(({
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "path#footpath",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
      "mound",
        "Solid ground rises up out of the swamp to form a mound, atop which\n"+
        "grows a willow tree.\n",
      "willow#willow tree#tree",
        "A weaping willow tree stands in the center of a small mound of earth.\n",
      "bole",
        "A hollow in the willow tree. It is large enough for a small animal or two.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
    }));
}
