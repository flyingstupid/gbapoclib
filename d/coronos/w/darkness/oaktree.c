#include <mudlib.h>
 
inherit ROOM;
 
void reset (status arg){
  if(arg) return;
 
  set_short("Atop a tree");
  set_long(
    "This is an oak tree.  Branches stretch outwards, and\n"+  
    "the great trunk shoots down to the ground.");
  set_day_desc(
    "  Sunlight\n"+
    "filters throught the tree's branches\n");
  set_night_desc(
    "  Moonlight\n"+
    "filters through the tree's branches.\n");
  set_items(({
      "tree#oak#oak tree",
      "This is a very large oak tree.  Its branches stretch out\n"+
      "from its great trunk.\n",
      "branches#branch",
      "These branches stretch out from the oak's trunk.\n",
      "trunk",
      "This is the tree's trunk.\n",
      "ground",
      "The ground is far below these upper branches of the tree.\n",
      }));
  set_smell( 
       "You smell the rich scent of the oak tree.\n");
  set_listen(
      "You hear the rustling of leaves.\n");
  set_weather(1, 4, 0);
  set_climb(6);
  set_fall_dam(10);
  set_exits(({
      "/d/coronos/w/darkness/walltop", "wall",
      "/d/coronos/w/darkness/treebase", "down",
      }));
}
