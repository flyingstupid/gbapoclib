#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 6");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "2.c", "northwest",
             PATH + "3.c", "north",
             PATH + "9.c", "south",
             PATH + "8.c", "southwest",
             PATH + "5f.c", "west",
             }) );
}


