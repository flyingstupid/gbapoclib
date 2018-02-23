#include <mudlib.h>
#include <ansi.h>
#include "path.h"

inherit "inherit/room2";

void reset(status arg) {
  reset_doors(arg);
  if(arg) return;

  load_door(({
    "destination", EDOOR "wh04.c",
    "destination", ROOMS "wh01.c",
    "direction", "northwest door",
    "description", "A set of solid double doors.  There is a padlock holding them closed.\n",
    "locked",
    "closed",
    "lock id", "padlock",
    "lock difficulty", 200,
    "key id", "whse",
    "lock description", "A large iron padlock.\n",
    "door number", 0,
  }));
  set_short("Dockside Street");
  set_long(RED_F+"\t--<Dockside Street>--\n"+OFF+
"As you continue along Dockside St. you are amazed at all the activity going\n"+
"on around you.  Dock workers bustling from place to place, hauling crates\n"+
"and boxes.  There dosen't seem to be a person here who dosen't have a reason\n"+
"for being here, with the exception of yourself.  You stick out like a sore\n"+
"thumb.  Dockside St. contunues to the north and southwest, to the south is\n"+
"a dock and to the northwest there is a large set of double doors.\n");
  set_weather(5, 4, 6);
  set_items(({"dock workers##workers",
"These are the men who keep these docks running.  Without them there would be\n"+
"no Ebony shipping center.\n",
    "crates##boxes",
"These contain all the precious cargo to be carried by the river boats.\n",
    "boats##river boats",
"You see them floating lazily at anchor in the middle of the river and some are\n"+
"moored to the docks.\n",
    "river",
"This is the mighty Ebony River from where the town got it's name.  The city\n"+
"of Ebony is nestled in a large curve in the river and surrounded on the south\n"+
"and west sides by water.\n",
    "docks",
"There is one to the south.\n",
  }));
  set_exits(({
    ROOMS "ds05.c", "north",
    ROOMS "d04.c", "south",
    ROOMS "ds03.c", "southwest",
  }));
}
