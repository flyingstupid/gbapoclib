/* yard.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if (!present("mailbox")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/items/mailbox"),this_object()); 
  }

  if(!present("chicken")) {
    int i;
    for(i=0; i<4; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/chicken"),this_object());}
  }

   reset_doors(0);
   load_door(({
   "destination",     "d/coronos/w/newstar/newbie/rooms/house1",
   "direction",       "front door",
   "closed",
   "description",
   "The front door of the farmhouse is made of oak and is a light blue colour.\n",
    }));

  if (arg) return;
 
  set_short("a farmhouse's front yard");
  set_long(
    "The main path comes to an end here, in front of a farm house.  A lesser path\n"+ 
    "leads north into the fields of the farm.  Another path leads west towards a \n"+
    "garden.  The two-story farmhouse stands to the east, and a barn can be seen \n"+
    "to the northwest.  Various plants and flowers border the front of the house,\n"+
    "adding to the simple beauty of the yard and the plains.  ");
  set_day_desc("\n");
  set_night_desc(
    "An oil lamp hangs by\n"+
    "the front of the door, lighting the yard and the front of the house.\n");
  set_items(({
    "path#down#ground",
      "There isn't anything special about the path.  Worn ground has given way to\n"+
      "dirt which makes up the path.  Pebbles and chicken feed also dot the path.\n",
    "chicken feed#feed",
      "The chicken feed is a mixture of different grains.\n",
    "fields",
      "The fields are far and wide.  Animals graze in the fields, while other fields\n"+
      "grow wheat and hay.\n",
    "animals",
      "Many different animals can be seen such as cows and horses.\n",
    "garden",
      "The large garden is to the west.  Many different kinds of vegetables could be\n"+
      "growing in it.  Rows and rows of plowed dirt can be seen from here.\n",
    "plants#flowers",
      "Many different plants and flowers grow along the front of the house.  The\n"+
      "colorfull flowers eminate a sweet smell into the air, and highlight the \n"+
      "house with their beauty.\n",
    "yard",
      "The front yard of the house is well kept and pretty.  Plants and flowers border the\n"+
      "front of the quaint farmhouse.\n",
    "house#farmhouse#farm house",
      "The farmhouse is a quaint two level building.  The wood planks that make up its\n"+
      "outer walls are painted red, and frames of the doors and windows are white.\n"+
      "Grey shingles cover the slanted roof, which is highlighted by a red, brick \n"+
      "smoke stack.  Cute, white curtains can be seen covering the windows, and adding\n"+
      "to the beauty of the house.\n",
   "barn",
      "The barn is a good ways off to the north west.  It looks like the path to the\n"+
      "north will lead you to the barn.  The barn a tall and wide building with large\n"+
      "doors.  They look to be cracked open from here.\n",
    }));
  set_day_items(({
    "lamp#oil lamp",
      "The simple lamp is unlit.  It is full of oil and in good condition.\n",
    }));
  set_night_items(({
    "lamp#oil lamp",
      "The simple lamp is lit, lighting the yard and the front of the house.\n"+
      "It is in good condition and ful of oil.\n",
    }));
  set_smell(
    "The fresh air of the plains fills your lungs.  The sweet smell of the flowers also\n"+
    "mingles in the air\n");
  set_listen(
    "The sound of a gentle breeze is all that can be heard.\n");
  set_weather(2, 4, 0);

  set_exits(({ 
      "d/coronos/w/newstar/newbie/rooms/field1", "north",
      "d/coronos/w/newstar/newbie/rooms/garden", "west",
      "d/coronos/w/newstar/newbie/rooms/path2",  "southwest",
      }));
}
