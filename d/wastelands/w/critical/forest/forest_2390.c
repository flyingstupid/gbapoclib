/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2390) );
    set_long( get_long_by_id(2390) );


    set_exits(({
        AREA_PATH + "forest_2339.c", "northwest",
        AREA_PATH + "forest_2340.c", "north",
        AREA_PATH + "forest_2341.c", "northeast",
        AREA_PATH + "forest_2389.c", "west",
        AREA_PATH + "forest_2391.c", "east",
        AREA_PATH + "forest_2439.c", "southwest",
        AREA_PATH + "forest_2440.c", "south",
        AREA_PATH + "forest_2441.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2390 ) );
}

