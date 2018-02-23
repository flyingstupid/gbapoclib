#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
   if (!present("guard")) {
        move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
        move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
 }      
 
  if(!arg) {
      set_short("Northwest Corner of the Castle");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"As you glance around the northwest corner of the castle, your eyes catch\n"+
"onto something lying on the floor south of here. You can't tell what it\n"+
"is from here, but it seems to be glowing and you have a strong urge to go\n"+
"and see exactly what it is.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"out4",  "south",
        CASTLE_ROOMS+"out6",  "east",
      }));
      set_weather(2,2,0);
      set_items(({
        "light#chandeliers#chandelier",
          "The chandeliers provide light for the room",
        "portraits#pictures#portrait#picture",
          "The pictures are of various members of minotaur\n"+
           "castle. They have all been framed in gold",
        "floor#tiles", "The tiles on the floor have been made from rich, "+
                       "white opals",
      }));
  }
}
