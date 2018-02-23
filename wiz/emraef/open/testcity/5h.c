#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 5h");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "5e.c", "north",
             PATH + "5i.c", "east",
             PATH + "5g.c", "west",
             PATH + "5d.c", "northwest",
             PATH + "5f.c", "northeast",
             PATH + "8.c", "south",
             }) );
}


