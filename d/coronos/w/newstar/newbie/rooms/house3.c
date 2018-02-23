/* house3.c -- newbie 
   The jar holds the key to the trunk in the cellar.
   The trunk holds a uniqe set of Newbie armour, thus the key should be hard to get.
   So, you only get the desc of the table.  Look at table to see jar. Look at jar.
   Open the jar, to get key... but jar is an invis object in the room.  Player
   uses room description to get key.  */
/* Darkness and Newstar */


#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if(!present("frying pan")) {
     move_object(clone_object(
     "d/coronos/w/newstar/newbie/items/fpan"),this_object()); 
  }

  if(!present("cookie jar")) {
     move_object(clone_object(
     "d/coronos/w/newstar/newbie/items/cjar"),this_object()); 
  }

  if(!present("cat")) {
     move_object(clone_object(
     "d/coronos/w/newstar/newbie/npc/cat"),this_object()); 
  }

  if(!present("Mrs Newman")) {
     move_object(clone_object(
     "d/coronos/w/newstar/newbie/npc/mother"),this_object()); 
  }  

  if(!present("canary")) {
    int i;
    for(i=0; i<2; i++) {
      move_object(clone_object(
      "d/coronos/w/newstar/newbie/npc/canary"),this_object());}
  }

  reset_doors(arg);
  load_door(({
    "file", "d/coronos/w/newstar/newbie/rooms/house4",  
    "secret door", 3,
    "long", "A small, cellar door in the floor",
    "secret door finders", ({}),
    "direction", "cellar door",
  }));

  if(arg) return;
 
  set_short("inside a farmhouse");
  set_long(
    "The kitchen of the farmhouse is small and tidy.  In the far corner of\n"+
    "the kitchen is a cast-iron stove.  Next to the stove is a small sink\n"+
    "and water pump.  A cupboard and table with two chairs are lined up \n"+
    "along one wall.  A blue rug adds color to the wooden floor.");
  set_day_desc(
    "  Sunlight\n"+
    "streams in through the small window above the sink, shining on a small\n"+
    "birdcage.\n");     
  set_night_desc(
    "  Moonlight\n"+
    "streams in through the small window above the sink, shining on a small\n"+
    "birdcage.\n");
  set_items(({
    "crack",
      "Through the crack appears to be another room below this one.\n",
    "floor#floor boards#floorboards",
      "Wooden floorboards make up the floor of the kitchen.  There is a\n"+
      "large crack between two floor boards close to the back of the room.\n",
    "rug",
      "This is a blue, coiled rug.  The blue and white pattern add color to\n"+
      "the plain floor boards of the kitchen.\n",
    "birdcage#cage",
      "This birdcage is made of shiny, silver metal.  It could house four\n"+
      "song birds comfortably\n",
    "wall#walls",
      "There is nothing special about the walls.  They are plain and simple\n"+
      "just like most of everything in the house.\n",
    "cupboard",
      "This wooden cupboard is old but sturdy.  It probably holds dishes and\n"+
      "food.  Intricate designs have been carved into the front panels.\n",
    "drain",
      "The drain is small and round.  It leads to the outside.\n",
    "sink",
      "The iron sink stands to the left of the water pump.  It is deep and\n"+
      "wide, with a drain emptying out to the outside.\n",
    "pump#water pump",
      "The metal water pump sits on the right side of the sink.\n",
    "cast-iron stove#stove",
      "This stove has been crafted from black iron.  It is compact and sturdy.\n"+
      "It looks very heavy.\n",
    "corner",
      "In the corner of the kitchen stands a cast-iron stove.\n",
    "farmhouse#house",
      "The farmhouse is small but comfy.  It has been well kept and in order.\n",
    "kitchen",
      "The kitchen is small and tidy.\n",
    "window",
      "The window has a wooden frame with several glass panels.\n"+
      "Curtains hang neatly along its sides.\n",
    "frame#wooden frame",
      "The frame is made from finely crafted oak.\n",
    "glass panels#glass#panels",
      "The glass panels fit snuggly into the wood frame.\n",
    "chair#chairs",
      "These two maple chairs are well made and sturdy.\n",
    "table",
      "The maple table is finely crafted and sturdy.  It is small and round,\n"+
      "and has a pair of matching chairs on either side.  A cookie jar sits\n"+
      "in the center of the tabletop.\n",
    "curtain#curtains",
      "These blue checkered curtains add a perfect touch to this kitchen.\n",
   }));
  set_smell(
    "The smell of oak permeates through this old house.  The smell\n"+
    "of all kinds of food also makes you a little hungry.\n");
  set_listen(
    "Now and then, you think you hear a rat scurrying beneath the\n"+
    "floor boards.\n");
  set_weather(2, 2, 0);

  set_exits(({ 
      "d/coronos/w/newstar/newbie/rooms/house1", "west",
      }));
}
