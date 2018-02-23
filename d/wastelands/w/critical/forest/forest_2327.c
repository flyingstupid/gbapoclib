/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2327) );
    set_long( get_long_by_id(2327) );


    set_exits(({
        AREA_PATH + "forest_2276.c", "northwest",
        AREA_PATH + "forest_2277.c", "north",
        AREA_PATH + "forest_2278.c", "northeast",
        AREA_PATH + "forest_2326.c", "west",
        AREA_PATH + "forest_2328.c", "east",
        AREA_PATH + "forest_2376.c", "southwest",
        AREA_PATH + "forest_2377.c", "south",
        AREA_PATH + "forest_2378.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2327 ) );
}

