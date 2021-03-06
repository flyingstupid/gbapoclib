/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2213) );
    set_long( get_long_by_id(2213) );


    set_exits(({
        AREA_PATH + "forest_2162.c", "northwest",
        AREA_PATH + "forest_2163.c", "north",
        AREA_PATH + "forest_2164.c", "northeast",
        AREA_PATH + "forest_2212.c", "west",
        AREA_PATH + "forest_2214.c", "east",
        AREA_PATH + "forest_2262.c", "southwest",
        AREA_PATH + "forest_2263.c", "south",
        AREA_PATH + "forest_2264.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2213 ) );
}

