#include <mudlib.h>
#include <ansi.h>
#include "path.h"

inherit "inherit/room2";

void reset(status arg) {
  reset_doors(arg);

  load_door(({
    "file", EDOOR "pa.c",
    "direction", "north door",
    "closed",
    "description", "A large oak door with brass fittings, there is a sign on the door\n",
  }));
  ::reset(arg);
  if(arg) return;
  set_short("Dockside Street");
  set_long(RED_F+"\t--<Dockside Street>--\n"+OFF+
"Your are on the southern most tip of Dockside St.  This is the shipping\n"+
"and receiving point of almost all trade to and from Ebony.  It was built\n"+
"shortly after the downfall of Baron Sardin and is one of the main reasons\n"+
"for the prosperity of the city.  As more and more of the realms trade\n"+
"passes through Ebony it will surely grow into a teaming metropolis.  To\n"+
"the north there is a door, dockside continues to the northeast, to the\n"+
"south is one of Ebony's quad docks and to the southwest is Center St. There\n"+
"is a sign on the north door.\n");
  set_weather(5, 4, 6);
  set_items(({"docks",
    "This is where the boats dock and launch from Ebony for other points in the\n"+
    "realm.\n",
    "sign",
    "Maybe you should try reading it.\n",
  }));
  set_exits(({
    ROOMS "ds02.c", "northeast",
    ROOMS "c01.c", "southwest",
    ROOMS "d01.c", "south",
  }));
}

void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if(!str) return 0;
  else if(str == "sign") {
    tell_object(this_player(), "Ebony Port Authority\n");
    return 1;
  }
  return 0;
}
