/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2419) );
    set_long( get_long_by_id(2419) );


    set_exits(({
        AREA_PATH + "forest_2368.c", "northwest",
        AREA_PATH + "forest_2369.c", "north",
        AREA_PATH + "forest_2370.c", "northeast",
        AREA_PATH + "forest_2418.c", "west",
        AREA_PATH + "forest_2420.c", "east",
        AREA_PATH + "forest_2468.c", "southwest",
        AREA_PATH + "forest_2469.c", "south",
        AREA_PATH + "forest_2470.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2419 ) );
}

