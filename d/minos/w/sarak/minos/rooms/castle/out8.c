#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

void reset(status arg) {
  if(!arg) {
      set_short("Northern Corridor");
      set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"This part of the northern corridor is very strange. Although the intense\n"+
"brightness still exists here, none of the usual items can be found. The\n"+
"portraits, chandeliers, tiles and overall exuberance that most of the\n"+
"rooms in the castle have is missing from here. The brightness comes from\n"+
"the west. However, to the east, lies only more darkness...\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      set_exits(({
        CASTLE_ROOMS+"out7", "west",
        CASTLE_ROOMS+"out9",  "east",
      }));
      set_weather(2,2,0);
  }
}

