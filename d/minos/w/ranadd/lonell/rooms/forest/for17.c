#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "The stench of decay sits heavily on the air. Shallow yet \n"+
      "stagnant, the lake, that feeds the swamp of Lonell, stretches\n"+
      "northward. Ancient pines, their numbers and girth great both \n"+
      "to the south and east, dwindle to the north. Off to the west\n"+
      "is a mound of earth and felled trees, while to the east, the\n"+
      "ground slopes down toward an inlet.\n"+   
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_exits(({
      FOREST_ROOMS+"for18", "east",
      FOREST_ROOMS+"for11", "south",
      FOREST_ROOMS+"for16", "west"
    }));
    set_items(({
      "swamp",
        "A dank swamp has overtaken the entire center of thes island.\n",
      "inlet",
        "A grassy inlet lays at the bottom of a footpath which leads down the\n"+
        "cliff face.\n",
      "mound",
        "A heaping mound of earth and branches rises above the muck to the west.\n"+
        "It is obviously the den of some animal.\n",
      "lake",
        "Large shallow pools of water cover the interior of the island. They meld\n"+
        "together so closely that they seem to be one large lake.\n",
      "pine#pines#pine trees#fir#fir trees",
        "Stately firs, they leave their needles on the ground creating a soft\n"+
        "blanket.\n",
    }));
}
