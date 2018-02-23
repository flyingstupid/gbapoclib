#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A row of pine trees creates a solid barrier, seperating the\n"+
      "forest from the swamp on the west, yet the dankness still \n"+
      "seeps through into the forest. Faint sounds of the ocean \n"+
      "drift in from the east. Ruts in the earth lead north, marking\n"+
      "a once well-used wagon trail.\n"+ 
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_listen("The sound of crashing waves drifts thru the trees.\n");
    set_exits(({
      FOREST_ROOMS+"for31", "north",
      FOREST_ROOMS+"for25", "east"
    }));
    set_items(({
      "pine#pines#pine trees#fir#fir trees#barrior",
        "Stately firs grow trunk to trunk leaving their needles on the ground,\n"+
        "creating a soft blanket.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "ruts#groves",
        "Permanent indentations in the earth mark the one-time trade route.\n",
    }));
}
