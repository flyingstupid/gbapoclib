/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1540) );
    set_long( get_long_by_id(1540) );


    set_exits(({
        AREA_PATH + "forest_1489.c", "northwest",
        AREA_PATH + "forest_1490.c", "north",
        AREA_PATH + "forest_1491.c", "northeast",
        AREA_PATH + "forest_1539.c", "west",
        AREA_PATH + "forest_1541.c", "east",
        AREA_PATH + "forest_1589.c", "southwest",
        AREA_PATH + "forest_1590.c", "south",
        AREA_PATH + "forest_1591.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1540 ) );
}

