#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 5d");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "5a.c", "north",
             PATH + "5g.c", "south",
             PATH + "5e.c", "east",
             PATH + "5b.c", "northeast",
             PATH + "5h.c", "southeast",
             PATH + "4.c", "west",
             }) );
}


