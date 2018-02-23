#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  int i, j;
  if (!present("servant")) {
    i = random(100);
    if (i < 50) {
      j = 1;
      i = random(3) + 1;
      while (j <= i) {
        move_object(clone_object(CASTLE_MONSTERS+"servant"), this_object());
	j++;
      }
    }
  }     
 
  if(!arg) {
      set_short("Western Corridor");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You find yourself walking along the western corridor of this magnificent\n"+
"castle. All around you is the radiance and bright glittering of gold and\n"+
"other rich treasures. Besides from the usual portraits, chandeliers and\n"+
"tiles, you find yourself drawn to something you can see on the floor in\n"+
"the room north of here.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"out2",  "south",
        CASTLE_ROOMS+"out4",  "north",
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
