/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1480) );
    set_long( get_long_by_id(1480) );


    set_exits(({
        AREA_PATH + "forest_1429.c", "northwest",
        AREA_PATH + "forest_1430.c", "north",
        AREA_PATH + "forest_1431.c", "northeast",
        AREA_PATH + "forest_1479.c", "west",
        AREA_PATH + "forest_1481.c", "east",
        AREA_PATH + "forest_1529.c", "southwest",
        AREA_PATH + "forest_1530.c", "south",
        AREA_PATH + "forest_1531.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1480 ) );
}

