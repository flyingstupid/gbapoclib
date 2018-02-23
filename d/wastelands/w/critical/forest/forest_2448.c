/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2448) );
    set_long( get_long_by_id(2448) );


    set_exits(({
        AREA_PATH + "forest_2397.c", "northwest",
        AREA_PATH + "forest_2398.c", "north",
        AREA_PATH + "forest_2399.c", "northeast",
        AREA_PATH + "forest_2447.c", "west",
        AREA_PATH + "forest_2449.c", "east",
        AREA_PATH + "forest_2497.c", "southwest",
        AREA_PATH + "forest_2498.c", "south",
        AREA_PATH + "forest_2499.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2448 ) );
}

