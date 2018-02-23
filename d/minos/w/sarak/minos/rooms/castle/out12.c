#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
   if (!present("guard")) {
        move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
        move_object(clone_object(CASTLE_MONSTERS+"guard"), this_object());
 }      
 
  if(!arg) {
    set_short("Southeast Corner of the Castle");
    set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You have found the southeast corner of the castle. This room glows\n"+
"raidently with gold, as do most of the other rooms within the castle.\n"+
"Although the rooms are bright and charming to look at, you can't help\n"+
"but feel that chandeliers, portraits and the opal tiles become a little\n"+
"bit boring. Perhaps there is something different on the upper floor.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");  
    set_exits(({
      CASTLE_ROOMS+"out11",  "north",
      CASTLE_ROOMS+"out13",  "west",
    }));
    set_weather(2,2,0);
    set_items(({
        "light#chandeliers#chandelier",
          "The chandeliers provide light for the room",
      "floor#tiles",  "The tiles on the floor have been made from rich whit opals",
      "portraits#portrait#picture#pictures", 
	  "The pictures are of various members of minotaur\n"+
	  "castle. They have all been framed in gold",
    }));
  }
}
