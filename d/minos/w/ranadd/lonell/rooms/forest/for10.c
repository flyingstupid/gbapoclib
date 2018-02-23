#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Deep claw marks mar the bark of several of the larger trees, \n"+
      "and long scratches have disturbed the blanket of leaves that\n"+
      "cover the entire forest. It would take a large mammal to \n"+
      "wreak this kind of havoc. One tree appears to have been \n"+
      "felled by the same large animal that has left its gouges \n"+
      "everywhere. The path opens up to the south, and the sounds of\n"+
      "the ocean can be heard not too far off in that direction.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_listen("The crashing of waves against the cliffs below is rather loud.\n");
    set_exits(({
      FOREST_ROOMS+"for4", "south",
      FOREST_ROOMS+"for9", "west"
    }));
    set_items(({
      "trees",
        "Tall trees populate the forest of Lonell.\n",
      "blanket",
        "A layer of foliage covers the ground in a natural blanket.\n",
      "path",
        "A path passes through the forest, mostly covered by leaves and branches.\n",
      "forest",
        "A dense forest stands along the perimeter of the island.\n",
      "tree",
        "A thick tree lays on its side north of the path, its roots forcefully \n"+
        "pulled from the soil, they now reach up into the air.\n",
      "scratches#gouges#claw marks",
        "The deep claw marks of a large mammal have distorted the natural beauty\n"+
        "of several trees and of the land itself.\n",
      "leaves#leaves and branches#leaf#foliage#litter",
        "The shed leaves of the trees of the forest lay on the ground, rustling\n"+
        "softly with each passing footstep.\n",
    }));
}
