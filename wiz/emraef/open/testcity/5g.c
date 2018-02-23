#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 5g");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "5d.c", "north",
             PATH + "5h.c", "east",
             PATH + "5e.c", "northeast",
             //PATH + "7.c", "southwest",
             }) );
}


