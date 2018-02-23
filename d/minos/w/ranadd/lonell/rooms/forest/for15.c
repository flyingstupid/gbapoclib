#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A foul-smelling swamp lays to the north and northeast of the \n"+
      "trail. The stench of decay and rot assault the nose. The \n"+
      "stark contrast between the bleakness of the swamp, and the \n"+
      "earthy greens of the forest is amazing. It is almost as if \n"+
      "an unseen wall divides the two areas. The trail runs away \n"+
      "from the swamp, leading west and south.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_exits(({
      FOREST_ROOMS+"for9", "south",
      FOREST_ROOMS+"for14", "west"
    }));
    set_items(({
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "trail",
        "A trail passes through the forest, mostly covered by leaves and branches.\n"
    }));
}
