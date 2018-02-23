#include <mudlib.h>
 
inherit ROOM;
 
void reset (status arg){
  if(arg) return;
  
  if(!present("Mic")){
    move_object(clone_object(
    "/d/coronos/w/darkness/npc/thief1"),
    this_object());
  }

  if(!present("Ray")){
    move_object(clone_object(
    "/d/coronos/w/darkness/npc/thief2"),
    this_object());
  }

  if(!present("Damon")){
    move_object(clone_object(
    "/d/coronos/w/darkness/npc/damon"),
    this_object());
  }

  set_short("The base of a tree");
  set_long(
      "This is a shady area under the oak tree.  There is a wall\n"+         
      "next to the tree with vines and moss growing on it.  Shrubs\n"+
      "and other plants surround the area.");
  set_day_desc(
      "  The sunlight filters\n"+
      "through the tree branches.\n");
  set_night_desc(
      "  The moonlight filters\n"+          
      "through the branches.\n");
  set_items(({
      "wall",
      "This is the wall that runs along Wall Street.  Its bricks are\n"+
      "made from red clay.  It is about one foot wide.\n",
      "bricks",
      "These bricks are made from red clay.\n",
      "tree#oak#oak tree",
      "This is a very large oak tree.  Its branches stretch out\n"+
      "from its great trunk.\n",
      "branches#branch",
      "These branches stretch out from the oak's trunk.\n",
      "trunk",
      "This is the tree's trunk.\n",
      "leaves#leaf",
      "These are oak leaves from the tree.\n",
      "vines#vine",
      "These green vine grow on the wall.\n",
      "moss",
      "This green moss grows in patches on the wall.\n",
      "shrub#shrubs",
      "A few varieties of shrubs grow in this area.\n",
      "plant#plants",
      "These are just common plants that grow in the area.\n",
      }));
  set_smell( 
      "You smell the rich scent of the oak tree and the other\n"+
      "plants that grow here.\n");
  set_listen(
      "You hear the rustling of leaves.\n");
  set_weather(1, 4, 0);
  set_climb(6);
  set_fall_dam(10);
  set_exits(({
      "/d/coronos/w/darkness/oaktree", "up",
      }));
}
