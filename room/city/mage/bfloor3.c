#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
/*
  if(!present("phylateracy")) {
    move_object(clone_object("room/city/obj/phy"),this_object());
  }
*/
  if(arg) return;

  set_short("the basement of the council of high magic");
  set_long(
     "Dark and dusty, this basement room has barely been used; possibly \n"+
     "forgotten by the wizards decades ago. Crates and boxes are stacked\n"+
     "against the far wall, containing old useless items.\n");

  set_items(({
     "crates#crate@box#boxes",
          "They are open and falling appart",
     "items#item",
          "Some are old spell components, others are parts of old "+
          "furniture",
     "furniture",
          "Old and broken parts of chairs and tables",
     "chair#chairs#table#tables",
          "They are of little use now",
     "walls#wall",
          "The walls are of a cold grey stone, possibly made by magical \n"+
          "magical means. They are covered with spots of blood and burn \n"+
          "marks from some intense fire or explosion",
     "stone",
          "No dwarf chiselled this stone",
  }));
  set_listen("There is a soft hum close by...\n");
  set_smell("There air is full of ozoone.\n");
  set_exits(({
     "room/city/mage/bfloor2", "west",
  }));
  set_weather(2,1,0);    
}
