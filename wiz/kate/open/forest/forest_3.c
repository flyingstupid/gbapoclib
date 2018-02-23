/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 5, 0, 0 );
    set_short( get_short_by_id(3) );
    set_long( get_long_by_id(3) );


    set_exits(({
        AREA_PATH + "forest_0.c", "north",
        AREA_PATH + "forest_1.c", "northeast",
        AREA_PATH + "forest_4.c", "east",
        AREA_PATH + "forest_6.c", "south",
        AREA_PATH + "forest_7.c", "southeast",
    }));

    set_room_type("forest");
}

