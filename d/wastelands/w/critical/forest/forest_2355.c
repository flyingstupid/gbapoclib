/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2355) );
    set_long( get_long_by_id(2355) );


    set_exits(({
        AREA_PATH + "forest_2304.c", "northwest",
        AREA_PATH + "forest_2305.c", "north",
        AREA_PATH + "forest_2306.c", "northeast",
        AREA_PATH + "forest_2354.c", "west",
        AREA_PATH + "forest_2356.c", "east",
        AREA_PATH + "forest_2404.c", "southwest",
        AREA_PATH + "forest_2405.c", "south",
        AREA_PATH + "forest_2406.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2355 ) );
}

