/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2323) );
    set_long( get_long_by_id(2323) );


    set_exits(({
        AREA_PATH + "forest_2272.c", "northwest",
        AREA_PATH + "forest_2273.c", "north",
        AREA_PATH + "forest_2274.c", "northeast",
        AREA_PATH + "forest_2322.c", "west",
        AREA_PATH + "forest_2324.c", "east",
        AREA_PATH + "forest_2372.c", "southwest",
        AREA_PATH + "forest_2373.c", "south",
        AREA_PATH + "forest_2374.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2323 ) );
}

