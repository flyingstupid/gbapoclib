/* house1.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if (!present("Mr Newman")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/npc/father"),this_object());
  }
 
  if (!present("Grandpa Newman")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/npc/grandpa"),this_object());
  }
 
  if (!present("dog")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/npc/dog3"),this_object());
  }
 
  if (!present("cat")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/cat"),this_object());
  }
 

   reset_doors(0);
   load_door(({
   "destination",     "d/coronos/w/newstar/newbie/rooms/yard",
   "direction",       "front door",
   "closed",
   "description",
   "The front door of the farmhouse is made of oak and is a light blue colour.\n",
    }));
 
  if (arg) return;
 
  set_short("inside a farmhouse");
  set_long(
    "This is a quaint little farmhouse.  A small couch, a few chairs, and\n"+
    "a small table furnish the cozy room.  A brick fireplace is built into\n"+
    "the wooden walls, and a few pictures form a patchwork over the wallpaper.\n"+
    "A narrow staircase leads to the upper floor of the house, and to the \n"+
    "east seems to be a small kitchen.");
  set_day_desc(
    "  Sunlight streams in through the\n"+
    "open windows.  ");  /* space for Door exit message*/
  set_night_desc(
    "  Moonlight streams in through the\n"+
    "open windows, and a fire in the fireplace lights the room.\n");
  set_items(({
    "stairs#staircase",
      "The wooden staircase is narrow and steep.  It leads up to the second\n"+
      "floor of the house.\n",
    "kitchen",
      "The kitchen seems to be to the east.\n",
    "windows#open windows",
      "These windows have a wooden frame with several glass panels.\n"+
      "They are bordered with a heavy curtain.\n",
    "frame#wooden frame",
      "The frame is made from finely crafted oak.\n",
    "glass panels#glass#panels",
      "The glass panels fit snuggly into the wood frame.\n",
    "red bricks#bricks",
      "These bricks are made from red clay.\n",
    "farmhouse#house#room",
      "This looks to be the main room of the farmhouse.\n",
    "couch",
      "The couch is made from soft animal skin.  It looks very comfy.\n",
    "chair#chairs",
      "These oak chairs are well made and sturdy.\n",
    "table",
      "The oak table is finely crafted and sturdy.  It looks like it has\n"+
      "been through many years of use.\n",
    "curtain#curtains",
      "The simple curtains are made from a white coth.\n",
    "pictures",
      "The many framed pictures hang along the walls.  The pictures are drawings\n"+
      "and some paintings of family members, family pets, and various scenic\n"+
      "depictions.\n",
    "wallpaper",
      "The walls are covered in a flower patterened wallpaper.\n",
   }));
  set_day_items(({
    "fireplace",
      "The fireplace is made from red bricks.\n",
    }));
  set_night_items(({
    "fire#fireplace",
      "The fire in the fireplace lights and warms the room.\n",
    }));
  set_smell(
    "The smell of oak permeates through this old house.\n");
  set_listen(
    "Crickets chirp softly from their hidden locations.\n");
  set_weather(2, 2, 0);
 
  set_exits(({
      "d/coronos/w/newstar/newbie/rooms/house3", "east",
      "d/coronos/w/newstar/newbie/rooms/house2",  "stairs",
      }));
}
