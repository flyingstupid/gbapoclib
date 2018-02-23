#include <mudlib.h>
#include <ansi.h>
#include "path.h"

inherit "inherit/room2";

void reset(status arg) {
  reset_doors(arg);
  if(arg) return;

  load_door(({
    "destination", EDOOR "ds02.c",
    "direction", "southeast door",
    "closed",
  }));

  set_short("Warehouse One");
  set_long(BLUE_F+"\t--<Warehouse One>--\n"+OFF+
"This is where they store the goods that are taken off of the river boats at\n"+
"the docks.  It is filled with almost every type of crate, box and chest ever\n"+
"imaginable.  The walls are lined from front to back and floor to ceiling.  It\n"+
"could easily take five or six days to find a particular box without some sort\n"+
"of inventory.  If you are caught in here you will be in for serious trouble.\n"+
"One of the few laws to survive from the previous regime was that when a thief\n"+
"is caught in the act, the punishment will be immediate death!  Be very careful.\n");
  set_weather(5, 4, 6);
  set_exits(({
  }));
}
