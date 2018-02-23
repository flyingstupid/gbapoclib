#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 8");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "7.c", "west",
             PATH + "9.c", "east",
             PATH + "4.c", "northwest",
             PATH + "6.c", "northeast",
             PATH + "5h.c", "north",
             }) );
}


