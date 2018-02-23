

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
        + "a table and chairs are here\n"
        + "\n"    );
    set_items(({
	  "chairs#chair",
        "a nice little chair\n"
        + "table#tables\n"
        + "a great old table\n"
        + "its very nice\n"
        + "i like it alot\n"
        + "it is blue\n"
        + "it is green\n"
        + "it can't even be seen!\n"
        + "\n",
    }));

    set_exits(({
        "/players/angel/workroom", "north",
        "/room/void", "south",
    }));
}

int query_room_maker() {
    return 205;
}

