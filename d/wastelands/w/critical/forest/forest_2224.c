/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2224) );
    set_long( get_long_by_id(2224) );


    set_exits(({
        AREA_PATH + "forest_2173.c", "northwest",
        AREA_PATH + "forest_2174.c", "north",
        AREA_PATH + "forest_2175.c", "northeast",
        AREA_PATH + "forest_2223.c", "west",
        AREA_PATH + "forest_2225.c", "east",
        AREA_PATH + "forest_2273.c", "southwest",
        AREA_PATH + "forest_2274.c", "south",
        AREA_PATH + "forest_2275.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2224 ) );
}

