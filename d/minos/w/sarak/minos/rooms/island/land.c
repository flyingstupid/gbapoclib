#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit "inherit/room2";

void reset(status arg) {
  if (arg) return;

  set_short("A small clearing");
  set_long (
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
   "As the rarely used track comes to an end, a small opening appears in\n"+
   "the middle of the forest. The sounds of the ocean seem barely a whisper\n"+
   "in this small part of the forest. The peaceful sounds of complete\n"+
   "silence are broken occasionally by cheerful birds playing in the trees.\n"+
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  set_weather(1,4,2);
  set_exits (({
    ISLAND_ROOMS+"start", "west",
  } ));
  set_land_value(1000000);
  set_items (({
    "track", "The track leads west through the rainforest.",
    "trees#tree#forest", "The dense rainforest is all around you.",
    "birds#bird", "You cannot see them, but you do hear them occasionally.",
  }));
}
