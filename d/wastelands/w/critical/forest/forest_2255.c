/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2255) );
    set_long( get_long_by_id(2255) );


    set_exits(({
        AREA_PATH + "forest_2204.c", "northwest",
        AREA_PATH + "forest_2205.c", "north",
        AREA_PATH + "forest_2206.c", "northeast",
        AREA_PATH + "forest_2254.c", "west",
        AREA_PATH + "forest_2256.c", "east",
        AREA_PATH + "forest_2304.c", "southwest",
        AREA_PATH + "forest_2305.c", "south",
        AREA_PATH + "forest_2306.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2255 ) );
}

