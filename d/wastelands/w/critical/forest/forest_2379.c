/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2379) );
    set_long( get_long_by_id(2379) );


    set_exits(({
        AREA_PATH + "forest_2328.c", "northwest",
        AREA_PATH + "forest_2329.c", "north",
        AREA_PATH + "forest_2330.c", "northeast",
        AREA_PATH + "forest_2378.c", "west",
        AREA_PATH + "forest_2380.c", "east",
        AREA_PATH + "forest_2428.c", "southwest",
        AREA_PATH + "forest_2429.c", "south",
        AREA_PATH + "forest_2430.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2379 ) );
}

