/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2400) );
    set_long( get_long_by_id(2400) );


    set_exits(({
        AREA_PATH + "forest_2350.c", "north",
        AREA_PATH + "forest_2351.c", "northeast",
        AREA_PATH + "forest_2401.c", "east",
        AREA_PATH + "forest_2450.c", "south",
        AREA_PATH + "forest_2451.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2400 ) );
}

