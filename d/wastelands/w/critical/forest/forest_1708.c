/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1708) );
    set_long( get_long_by_id(1708) );


    set_exits(({
        AREA_PATH + "forest_1657.c", "northwest",
        AREA_PATH + "forest_1658.c", "north",
        AREA_PATH + "forest_1659.c", "northeast",
        AREA_PATH + "forest_1707.c", "west",
        AREA_PATH + "forest_1709.c", "east",
        AREA_PATH + "forest_1757.c", "southwest",
        AREA_PATH + "forest_1758.c", "south",
        AREA_PATH + "forest_1759.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1708 ) );
}

