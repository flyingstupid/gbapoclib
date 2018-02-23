

/*
H7 Players' Keeps Rooms. v204 
*/
#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
    if (arg) return;

    set_weather(2, 1, 0);
    set_short("the deep blue sea");
    set_long(
        "Angel's room.\n"
        + "It needs a little work.\n"
        + "\n"    );
    set_items(({
	  "chair#chairs",
	  "nice chairs",
	  "table#tables",
	  "nice tables they are!",
    }));

    set_exits(({
        "north", "/room/void",
        "south", "0",
    }));
}

int query_room_maker() {
    return 204;
}

