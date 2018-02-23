/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2341) );
    set_long( get_long_by_id(2341) );


    set_exits(({
        AREA_PATH + "forest_2290.c", "northwest",
        AREA_PATH + "forest_2291.c", "north",
        AREA_PATH + "forest_2292.c", "northeast",
        AREA_PATH + "forest_2340.c", "west",
        AREA_PATH + "forest_2342.c", "east",
        AREA_PATH + "forest_2390.c", "southwest",
        AREA_PATH + "forest_2391.c", "south",
        AREA_PATH + "forest_2392.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2341 ) );
}

