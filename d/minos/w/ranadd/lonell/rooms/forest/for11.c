#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Fallen leaves cover the forest floor, blanketing it in gentle\n"+
      "browns and greys. The musty smell of decay permiates the air,\n"+
      "and the soft sounds of crashing waves can be heard from the \n"+
      "south and east. Tall trees of great girth stand all around,\n"+
      "their countless branches stretching ever skyward. These great\n"+
      "behemouths block travel to both the east and west.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_listen("The sound of crashing waves drifts thru the trees.\n");
    set_exits(({
      FOREST_ROOMS+"for17", "north",
      FOREST_ROOMS+"for5", "south"
    }));
    set_items(({
      "branches",
        "Thick arms of the trees of the forest. The stretch ever skyward.\n",
      "trees",
        "Tall trees populate the forest of Lonell.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "blanket",
        "A layer of foliage covers the ground in a natural blanket.\n",
      "leaves#leaves and branches#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
    }));
}
