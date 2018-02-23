/* house2.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if (!present("bobby")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/npc/bobby.c"),this_object()); 
  }

  if (!present("cindy")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/npc/cindy.c"),this_object()); 
  }  

  if (!present("dog")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/npc/dog2"),this_object()); 
  }

  if (!present("puppy")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/dog1"),this_object()); 
  }

  if (arg) return;
 
  set_short("the upstairs of a farmhouse");
  set_long(
    "The upstairs of the farmhouse is very small and cramped.  Though it's a\n"+
    "tight fit, the Newman family is quite comfortable using this room as   \n"+
    "the bedroom.  There is a small bed up against the wall, and two feather\n"+
    "mattresses laying across the floor.  Some blankets and a few pillows   \n"+
    "are neatly stacked in one corner of the room.  Two trunks and a few    \n"+
    "dressers are crammed together along one wall.  Various items such as   \n"+
    "children's toys are scattered on floor.  The staircase that leads down \n"+
    "to the first floor is very steep and narrow.\n");
  set_items(({
    "toys#toy",
      "A few toys are scattered about the floor of the room.  Blocks and\n"+
      "dolls make up the majority of the toys.\n",
    "blocks#blocks",
      "These are wooden blocks with letters painted on them.\n",
    "doll#dolls",
      "These dolls are of all sizes and colors.  Some are finely made, but\n"+
      "most of them are rag dolls, with missing button eyes.\n",
    "floor",
      "Other than a few toys, the floor is spotlessly clean.\n",
    "dresser#dressers",
      "The dressers are old and made of wood.  They probably hold clothes\n"+
      "and other such items.\n",
    "trunk#trunks",
      "One of the wooden trunks is closed, but the other trunk is open.  The\n"+
      "trunk holds many different kinds of children's toys.\n",
    "corner",
      "The corner of the room is covered by a stack of blankets and pillows.\n",
    "blankets#blanket#pillow#pillows",
      "Many blankets of all sizes and colors are neatly stacked in the corner\n"+
      "of the room.  There is nothing unusual about them.\n",
    "bed",
      "This bed is quite old.  It is handmade and simple in nature.\n",
    "mattresses#mattress",
      "These simple mattresses are two, large sheets of cloth, sewn along the\n"+
      "sides and stuffed with lots of bird feathers.\n",
    "stairs#staircase",
      "The wooden staircase is narrow and steep.  It leads down to the first\n"+
      "floor of the house.\n",
    "wall#walls",
      "The walls of this floor are wallpapered, and the windows have the same\n"+
      "look as those of the first floor.\n",
    "windows#open windows",
      "These windows have a wooden frame with several glass panels.\n"+
      "They are bordered with a heavy curtain.\n",
    "frame#wooden frame",
      "The frame is made from finely crafted oak.\n",
    "glass panels#glass#panels",
      "The glass panels fit snuggly into the wood frame.\n",
    "farmhouse#house#room#upstairs#bedroom",
      "This is the second floor bedroom of the farmhouse.\n",
    "curtain#curtains",
      "The simple curtains are made from a white coth.\n",
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
      "d/coronos/w/newstar/newbie/rooms/house1",  "stairs",
      }));
}
