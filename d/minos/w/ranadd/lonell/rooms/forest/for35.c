#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The cliffs of the island lead to the east and south, as does \n"+
      "the wagon trail. The grooves in the ground - deeper to the \n"+
      "east, become less obvious south of this corner of the trail.\n"+
      "The swamp encroaches upon this part of the forest from the \n"+
      "north and west, however a small path of solid ground leads \n"+
      "into the swamp to the northwest.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_exits(({
      FOREST_ROOMS+"for36", "east",
      FOREST_ROOMS+"for32", "south",
      FOREST_ROOMS+"for42", "northwest"
    }));
    set_items(({
      "cliff#cliffs#cliff face",
        "High cliffs rise out of the ocean, encasing the entire island.\n",
      "ruts#groves#wagon trail#trail",
        "Permanent indentations in the earth mark the one-time trade route.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
    }));
}
