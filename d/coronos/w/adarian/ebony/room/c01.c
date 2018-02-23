#include <mudlib.h>
#include <ansi.h>
#include "path.h"
inherit "inherit/room2";

void reset(status arg) {
  if(arg) return;

  set_short("Center Street");
  set_long(CYAN_F+"\t--<Center Street>--\n"+OFF+
"This is the southern most portion of Center St.  The citizens of Ebony brush\n"+
"past you swiftly as they hasten to thier destinations.  The streets are clean\n"+
"and neat, free of rubbish common to other cities.  It was not always this way,\n"+
"but since the election of Mayor Gerald the city has been cleaned up.  Despite\n"+
"the city's clean appearance, there seems to be something sinister in the\n"+
"air.  Center St. continues to the north, to the west is ????? and to the\n"+
"northwest is Dockside St., to the south is the city's South Bridge entrance.\n");
"northwest is Dockside St., to the south is the city's South Bridge entrance.\n"+
  set_weather(5, 4, 6);
  set_items(({"citizens",
    "These are the residents of this fine city.\n",
    "streets",
    "You're standing on one of them silly.\n",
    "rubbish",
    "There is none here, it's a very clean city.\n",
  }));
  set_exits(({
    ROOMS "c02.c", "north",
    ROOMS "ds01.c", "northeast",
    ROOMS "b01.c", "south",
    ROOMS "aaa.c", "west",
  }));
}
