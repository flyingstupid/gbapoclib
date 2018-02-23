#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 5e");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "5b.c", "north",
             PATH + "5c.c", "northeast",
             PATH + "5a.c", "northwest",
             PATH + "5f.c", "east",
             PATH + "5d.c", "west",
             PATH + "5h.c", "south",
             PATH + "5g.c", "southwest",
             PATH + "5i.c", "southeast",
             }) );
}


