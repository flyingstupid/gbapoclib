/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1656) );
    set_long( get_long_by_id(1656) );


    set_exits(({
        AREA_PATH + "forest_1605.c", "northwest",
        AREA_PATH + "forest_1606.c", "north",
        AREA_PATH + "forest_1607.c", "northeast",
        AREA_PATH + "forest_1655.c", "west",
        AREA_PATH + "forest_1657.c", "east",
        AREA_PATH + "forest_1705.c", "southwest",
        AREA_PATH + "forest_1706.c", "south",
        AREA_PATH + "forest_1707.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1656 ) );
}

