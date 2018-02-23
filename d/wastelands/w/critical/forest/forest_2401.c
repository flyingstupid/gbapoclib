/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2401) );
    set_long( get_long_by_id(2401) );


    set_exits(({
        AREA_PATH + "forest_2350.c", "northwest",
        AREA_PATH + "forest_2351.c", "north",
        AREA_PATH + "forest_2352.c", "northeast",
        AREA_PATH + "forest_2400.c", "west",
        AREA_PATH + "forest_2402.c", "east",
        AREA_PATH + "forest_2450.c", "southwest",
        AREA_PATH + "forest_2451.c", "south",
        AREA_PATH + "forest_2452.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2401 ) );
}

