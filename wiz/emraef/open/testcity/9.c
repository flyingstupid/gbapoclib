#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 9");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "6.c", "north",
             PATH + "8.c", "west",
             //PATH + "5i.c", "northwest",
             }) );
}


