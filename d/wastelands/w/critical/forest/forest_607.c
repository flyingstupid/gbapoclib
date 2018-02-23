/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(607) );
    set_long( get_long_by_id(607) );


    set_exits(({
        AREA_PATH + "forest_556.c", "northwest",
        AREA_PATH + "forest_557.c", "north",
        AREA_PATH + "forest_558.c", "northeast",
        AREA_PATH + "forest_606.c", "west",
        AREA_PATH + "forest_608.c", "east",
        AREA_PATH + "forest_656.c", "southwest",
        AREA_PATH + "forest_657.c", "south",
        AREA_PATH + "forest_658.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 607 ) );
}

