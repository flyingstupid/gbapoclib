

/*
H7 Players' Keeps Rooms. v205 
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
        + "it has a chair and a table\n"
        + "\n"    );
    set_items(({
	  "chair#chairs",
"      nice green chairs\n"
+ "      they are pretty comfy!\n"
+ "      \n",
	  "table#tables",
"      a coffee table\n"
+ "      \n",
    }));

    set_exits(({
        "/players/angel/workroom", "north",
        "/room/void", "south",
    }));
}

int query_room_maker() {
    return 205;
}

