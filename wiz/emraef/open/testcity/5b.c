#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 5b");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "5a.c", "west",
             PATH + "5d.c", "southwest",
             PATH + "5e.c", "south",
             PATH + "5f.c", "southeast",
             PATH + "5c.c", "east",
             PATH + "2.c", "north",
             }) );
}


