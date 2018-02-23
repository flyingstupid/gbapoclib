/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2413) );
    set_long( get_long_by_id(2413) );


    set_exits(({
        AREA_PATH + "forest_2362.c", "northwest",
        AREA_PATH + "forest_2363.c", "north",
        AREA_PATH + "forest_2364.c", "northeast",
        AREA_PATH + "forest_2412.c", "west",
        AREA_PATH + "forest_2414.c", "east",
        AREA_PATH + "forest_2462.c", "southwest",
        AREA_PATH + "forest_2463.c", "south",
        AREA_PATH + "forest_2464.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2413 ) );
}

