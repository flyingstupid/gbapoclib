/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1756) );
    set_long( get_long_by_id(1756) );


    set_exits(({
        AREA_PATH + "forest_1705.c", "northwest",
        AREA_PATH + "forest_1706.c", "north",
        AREA_PATH + "forest_1707.c", "northeast",
        AREA_PATH + "forest_1755.c", "west",
        AREA_PATH + "forest_1757.c", "east",
        AREA_PATH + "forest_1805.c", "southwest",
        AREA_PATH + "forest_1806.c", "south",
        AREA_PATH + "forest_1807.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1756 ) );
}

