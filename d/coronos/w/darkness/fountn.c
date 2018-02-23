#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  if(!present("fountain")){
  move_object(clone_object(
  "/d/coronos/w/darkness/items/fntn1"),
  this_object());
  }  

  set_short("A Fountain Square");
  set_long(
    "This is a small square with a fountain in the center.  It borders\n"+
    "Main Street and East Road, allowing a nice area to sit and relax.\n"+
    "A small path leads to the west where a gazebo provides shade from \n"+
    "the hot sun.  Stone benches are lined around the fountain, and next\n");
  set_day_desc(
    "to each bench is a small lamp post that provides light at night.\n");
  set_night_desc(
    "to each bench is a small lamp that lights up the area.\n");
  set_items(({
    "stone",
    "The stone is some plain grey stone, smoothed over time.\n",
    "water",
    "The water looks crystal clear, cold, and refreshing.\n",
    "angel",
    "This is possibly an angel to the All-God as an artist would depict it.\n"+
    "The craftsman did a great job with the intricate details from its\n"+
    "long flowing hair, to the feathers in its great wings.\n",
    "square",
    "This is a small area made of stone for the city folk to sit and\n"+
    "relax.  There are several stone benches situated around the fountain\n"+
    "in the center.",
    "benches#bench",
    "These benches are made from smoth grey stone.  They look quite comfy.\n",
    "path",
    "A short path leads west towards a shady gazebo.\n",
    "gazebo",
    "The gazebo is to the west.  It looks like it's covered in vines.\n",
    "stone",
    "The smooth grey stone looks like it has held up for many years.\n",
    "carvings#runes",
    "These carvings and runes are very old.  Most are too worn to even\n"+
    "attempt to decipher them.\n",
    "vine#vines",
    "The green vines grow on the gazebo to the west.\n",
    }));
  set_day_items(({
    "lamp post#lamp",
    "This lamp post is made from iron, and is engraved with intricate\n"+
    "designs.  It has a cylindrical top that house the oil and wick.\n"+
    "It is currently unlit.\n", 
    }));  
  set_night_items(({
    "lamp post#lamp",
    "This lamp post is made from iron, and is engraved with intricate\n"+
    "designs.  It has a cylindrical top that house the oil and wick.\n"+
    "It burns brightly, illuminating the road.\n",
    }));
  set_smell(
     "You smell nothing but fresh air.\n");
  set_listen(
      "You hear the water trickling from the fountain.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/mainst4", "south",
      "/d/coronos/w/darkness/eastrd5", "east",
      "/d/coronos/w/darkness/gazebo1.c", "west",
      "/d/coronos/w/darkness/mainst5", "southeast",
      }));
}
