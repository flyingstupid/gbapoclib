#include <mudlib.h>
#include <ansi.h>
#include "path.h"

inherit "inherit/room2";

void reset(status arg) {
  if(arg) return;
  set_short("Dockside Street");
  set_long(RED_F+"\t--<Dockside Street>--\n"+OFF+
"You are on the northern most tip of Dockside St.  This is the shipping\n"+
"and receiving point of almost all trade to and from Ebony.  It was built\n"+
"shortly after the downfall of Baron Sardin and is one of the main reasons\n"+
"for the prosperity of the city.  As more and more of the realms trade\n"+
"passes through Ebony it will surely grow into a teaming metropolis.  To\n"+
"the northeast is Chalice St. and Dockside St. continues to the south.\n");
  set_weather(5, 4, 6);
  set_items(({"docks",
    "This is where the boats dock and launch from Ebony for other points in the\n"+
    "realm.\n",
    "sign",
    "Maybe you should try reading it.\n",
  }));
  set_exits(({
    ROOMS "ch01.c", "northeast",
    ROOMS "ds04.c", "south",
  }));
}
