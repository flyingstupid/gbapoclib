#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 4");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "1.c", "north",
             PATH + "2.c", "northeast",
             PATH + "7.c", "south",
             PATH + "8.c", "southeast",
             PATH + "5d.c", "east",
             }) );
}


