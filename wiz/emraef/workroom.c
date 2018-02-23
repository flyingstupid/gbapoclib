#include <mudlib.h>
inherit ROOM;


void reset(status arg) {
    if (arg) return;

    set_short("a standard workroom");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 1, 1);
    set_exits(({
        "/d/wastelands/w/critical/secondtry/city2.c", "down",
        "/wiz/emraef/workroom2.c", "east",
        "/wiz/emraef/open/maze/1.c", "south",
    }));
}
