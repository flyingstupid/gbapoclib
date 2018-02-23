/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2292) );
    set_long( get_long_by_id(2292) );


    set_exits(({
        AREA_PATH + "forest_2241.c", "northwest",
        AREA_PATH + "forest_2242.c", "north",
        AREA_PATH + "forest_2243.c", "northeast",
        AREA_PATH + "forest_2291.c", "west",
        AREA_PATH + "forest_2293.c", "east",
        AREA_PATH + "forest_2341.c", "southwest",
        AREA_PATH + "forest_2342.c", "south",
        AREA_PATH + "forest_2343.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2292 ) );
}

