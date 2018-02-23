#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 2");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "3.c", "east",
             PATH + "1.c", "west",
             PATH + "4.c", "southwest",
             PATH + "6.c", "southeast",
             PATH + "5b.c", "south",
             }) );
}


