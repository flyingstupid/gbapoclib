/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2283) );
    set_long( get_long_by_id(2283) );


    set_exits(({
        AREA_PATH + "forest_2232.c", "northwest",
        AREA_PATH + "forest_2233.c", "north",
        AREA_PATH + "forest_2234.c", "northeast",
        AREA_PATH + "forest_2282.c", "west",
        AREA_PATH + "forest_2284.c", "east",
        AREA_PATH + "forest_2332.c", "southwest",
        AREA_PATH + "forest_2333.c", "south",
        AREA_PATH + "forest_2334.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2283 ) );
}

