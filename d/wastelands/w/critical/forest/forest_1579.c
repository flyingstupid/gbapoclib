/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1579) );
    set_long( get_long_by_id(1579) );


    set_exits(({
        AREA_PATH + "forest_1528.c", "northwest",
        AREA_PATH + "forest_1529.c", "north",
        AREA_PATH + "forest_1530.c", "northeast",
        AREA_PATH + "forest_1578.c", "west",
        AREA_PATH + "forest_1580.c", "east",
        AREA_PATH + "forest_1628.c", "southwest",
        AREA_PATH + "forest_1629.c", "south",
        AREA_PATH + "forest_1630.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1579 ) );
}

