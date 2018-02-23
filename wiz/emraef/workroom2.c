#include <mudlib.h>

inherit ROOM;

void reset(status arg) {
    if (arg) return;

    set_short("Forest");
    set_long ("This is a test room of the scavenge system.\n");
    set_weather(5, 5, 5);
    set_exits(({
        "/wiz/emraef/workroom.c", "west",
        "/wiz/emraef/storeroom.c", "south",
    }));

    set_room_type( "forest" );
}
