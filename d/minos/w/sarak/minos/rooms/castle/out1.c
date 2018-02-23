#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if(!arg) {
    set_short("The Outer Hall of the Castle");
    set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You are walking along the hall which surrounds the castle. The whole room\n"+
"is glittering with gold. The chandeliers hanging from the ceiling provide\n"+
"the room with a gold glow. The tiles on the floor reflect the light from\n"+
"the chandeliers to highlight the portraits hanging from the wall.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");  
    set_exits(({
      CASTLE_ROOMS+"entrance",  "east",
      CASTLE_ROOMS+"out2",  "west",
    }));
    set_weather(2,2,0);
    set_items(({
        "light#chandeliers#chandelier",
          "The chandeliers provide light for the room",
      "portraits#portrait#picture#pictures",
          "The pictures are of various members of minotaur\n"+
          "castle. The have all been framed in gold",
      "floor#tiles",  "The tiles on the floor have been made from rich white opals",
    }));
  }
}
