#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if(!arg) {
      set_short("Northern Corridor");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You are walking down the northen corridor of the castle. There's nothing\n"+
"that you find really special about this room. There's the usual tiles,\n"+
"chandeliers and floor tiles, but that's about it. The only thing that is\n"+
"even remotely interesting is the strange glow of light coming from the\n"+
"east room.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"out5",  "west",
        CASTLE_ROOMS+"out7",  "east",
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
