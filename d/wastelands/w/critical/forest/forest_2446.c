/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2446) );
    set_long( get_long_by_id(2446) );


    set_exits(({
        AREA_PATH + "forest_2395.c", "northwest",
        AREA_PATH + "forest_2396.c", "north",
        AREA_PATH + "forest_2397.c", "northeast",
        AREA_PATH + "forest_2445.c", "west",
        AREA_PATH + "forest_2447.c", "east",
        AREA_PATH + "forest_2495.c", "southwest",
        AREA_PATH + "forest_2496.c", "south",
        AREA_PATH + "forest_2497.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2446 ) );
}

