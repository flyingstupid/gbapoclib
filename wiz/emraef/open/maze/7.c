#include <mudlib.h>
inherit ROOM;


void reset(status arg) {
    if (arg) return;

    set_short("a maze");
    set_long ("This is a room in a maze they all look the same\n");
    set_weather(5, 5, 5);
    set_exits(({
        "/wiz/emraef/open/maze/8.c", "north",
        "/wiz/emraef/open/maze/1.c", "south",
        "/wiz/emraef/open/maze/1.c", "east",
        "/wiz/emraef/open/maze/1.c", "west",
        "/wiz/emraef/open/maze/1.c", "northeast",
        "/wiz/emraef/open/maze/1.c", "northwest",
        "/wiz/emraef/open/maze/1.c", "southeast",
        "/wiz/emraef/open/maze/1.c", "southwest",
    }));
}
