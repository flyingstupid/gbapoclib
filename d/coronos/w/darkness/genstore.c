/*General Store*/
/*Darkness*/

#include <mudlib.h>
inherit STORE;

object galdon;

 
void reset(status arg) {
  owner = "Galdon";
  reset_doors(arg);

  load_door(({
     "file", "d/coronos/w/alena/ille/c_8.c",
     "direction", "west door",
     "long",
          "A huge iron bound set of double doors.\n",
  }));
 
  if(!galdon) {
    galdon = clone_object("d/coronos/w/angel/city/monst/galdon");
    move_object(galdon, this_object());
  }
  if(!present("dwarf")) {
    move_object(clone_object("inherit/dwarf"), this_object());
  }


  if(arg) return;
  set_short("the General Store");
  set_long(
    "\t#-Coronos General Store-#\n"+
    "The general store of Ille Coronos is a somewhat large, one floor building.\n"+
    "Thick logs make up the walls, with large stones making up door and window\n"+
    "frames.  There is a long counter at the far end of the room where purchases\n"+
    "can be made.  Next to the counter is a list of all items that are available\n"+
    "at this time.\n");
  set_items(({
    "store#building",
      "The general store is rather large and full of various items for sale.\n",
    "floor",
      "The floor is made of stone.\n",
    "stone",
      "The stone is dark grey and somewhat rough.\n"+
    "logs",
      "The logs are very large and strong.  The are fastened tight together with\n"+
      "clay and other cements to form the walls of the store.\n",
    "door frame#window frame",
      "The door and window frames have been made by intricately arranging\n"+
      "large stones into tightly formed arches.\n",
    "counter",
      "The long counter is made of oak.  It has a list tacked to it showing\n"+
      "the various things for sale right now.\n",
   }));




  add_sell_items("clothing");
  add_sell_items("container");


  set_sell_weapon();
  set_sell_armour();
  set_sell_treasure();
 
  set_weather(2,1,0);
}

void long(status wiz) {
  ::long(wiz);
  if(!present("Galdon")) 
    write("The shop seems to be locked up for the night.\n");
}

