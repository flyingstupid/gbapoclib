#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 5f");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "5c.c", "north",
             PATH + "5i.c", "south",
             PATH + "5b.c", "northwest",
             PATH + "5h.c", "southwest",
             PATH + "5e.c", "west",
             PATH + "6.c", "east",
             }) );
}


