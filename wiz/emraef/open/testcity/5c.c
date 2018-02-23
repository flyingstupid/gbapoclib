#include <mudlib.h>
inherit ROOM;

#define PATH "/wiz/emraef/open/testcity/"


void reset(status arg) {
    if (arg) return;

    set_short("ROOM 5c");
    set_long ("This is a standard workroom. Work on it.\n");
    set_weather(5, 5, 5);
    set_exits( ({
             PATH + "5b.c", "west",
             PATH + "5e.c", "southwest",
             PATH + "5f.c", "south",
             //PATH + "3.c", "northeast",
             }) );
}


