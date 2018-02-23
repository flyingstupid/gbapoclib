#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A row of pines creates an impassable barrier between the \n"+
      "forest and the swamp west and north of the shallow remains of\n"+
      "a long since forgetten wagon trail. The trail itself is \n"+
      "almost completely hidden under decades of fallen needles, but\n"+
      "leads south and east along the tree line.\n"+ 
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_listen("The sound of crashing waves drifts thru the trees.\n");
    set_exits(({
      FOREST_ROOMS+"for32", "east",
      FOREST_ROOMS+"for24", "south"
    }));
    set_items(({
      "pine#pines#pine trees#fir#fir trees#barrior",
        "Stately firs grow trunk to trunk leaving their needles on the ground,\n"+
        "creating a soft blanket.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "ruts#groves#wagon trail#trail",
        "Permanent indentations in the earth mark the one-time trade route.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
    }));
}
