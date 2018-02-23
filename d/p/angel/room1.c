

/*
H7 Players' Keeps Rooms. v204 
*/
#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
    if (arg) return;

    set_weather(1, 1, 0);
    set_short("a room #1");
    set_long(
        "long 1\n"
        + "long 2\n"
        + "long 3\n"
        + "long 4\n"
        + "\n"    );
    set_items(({
	  "nice little chairs",
	  "chair#chairs",
	  "nice little tables",
	  "table#tables",
    }));

    set_exits(({
        "/players/angel/workroom", "south",
        "/room/void", "0",
    }));
}

string query_room_maker() {
    return 204;
}

