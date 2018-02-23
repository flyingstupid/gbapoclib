/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(100) );
    set_long( get_long_by_id(100) );


    set_exits(({
        AREA_PATH + "forest_50.c", "north",
        AREA_PATH + "forest_51.c", "northeast",
        AREA_PATH + "forest_101.c", "east",
        AREA_PATH + "forest_150.c", "south",
        AREA_PATH + "forest_151.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 100 ) );
}

