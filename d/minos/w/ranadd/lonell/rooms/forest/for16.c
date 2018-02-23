#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "A vast swamp lays just to the north. Smells of rot and decay \n"+
      "permiate the air, assaulting the nostrils. The ground is \n"+
      "muddy and sucks at the foot. A large tree, scared with deep \n"+
      "claw marks, has been felled to the south, while a mound of \n"+
      "earth and trees blocks the way west.\n"+ 
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_smell(
      "You inhale a deep breath of air, hoping to get a sniff of your\n"+
      "your surroundings and your lungs fill with the stench of rotting\n"+
      "leaves and stangnant waters, nearly making you lose your appetite\n"+
      "for lunch.\n");
    set_exits(({
      FOREST_ROOMS+"for17", "east"
    }));
    set_items(({
      "mound",
        "A heaping mound of earth and branches rises above the muck. It is obviously\n"+
        "the den of some animal.\n",
      "tree",
        "A thick tree lays on its side to the south, its roots forcefully pulled\n"+
        "from the soil, they now reach up into the air.\n",
      "swamp",
        "A dank swamp has overtaken the entire center of the island.\n",
      "trail",
        "A trail passes through the forest, mostly covered by leaves and branches.\n",
      "scratches#gouges#claw marks",
        "The deep claw marks of a large mammal have distorted the natural beauty\n"+
        "of several trees and of the land itself.\n",
    }));
}
