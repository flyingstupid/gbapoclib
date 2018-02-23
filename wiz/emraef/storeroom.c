#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h"

// uncomment to enable saving
//#define ENABLE_SAVE

inherit STORE_ROOM;

//-----------------------------------------------------------------
void reset(status arg) {

    ::reset(arg);

    if (arg) return;

    set_short("Emraef's Store Room");
    set_long ("This is a test room of the storage system.\n");
    set_weather(5, 0, 0);
    set_exits(({
        "/wiz/emraef/workroom2.c", "north",
    }));
}

