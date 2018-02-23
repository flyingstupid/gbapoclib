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
"Lying on the ground in this part of the western corridor is a beautiful\n"+
"gold rug. On closer inspection, you realise that it is not just in the\n"+
"colour of gold, but it is actually made from gold! Someone with a lot of\n"+
"patience has taken thousands of small strands of gold and weaved them\n"+
"together to make this fine rug. The rug adds to the splendor of these\n"+
"already beautiful rooms.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"out3",  "south",
        CASTLE_ROOMS+"out5",  "north",
      }));
      set_weather(2,2,0);
      set_items (({
        "light#chandeliers#chandelier",
          "The chandeliers provide light for the room",
        "portraits#pictures#portrait#picture",
          "The pictures are of various members members of minotaur\n"+
          "castle. They have all been framed in gold",
        "tiles#floor", 
          "The tiles on the floor have been made from rich, white opals",
        "rug",  "This rug is magnificent. You cannot believe your eyes! It\n"+
          "has been woven from fine strands of gold and must be extremely\n"+
          "valuable. You can't help but wonder why it has been left in this\n"+
          "part of the castle.",
      }));
  }
}
