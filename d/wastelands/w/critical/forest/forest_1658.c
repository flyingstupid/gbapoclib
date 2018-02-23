/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1658) );
    set_long( get_long_by_id(1658) );


    set_exits(({
        AREA_PATH + "forest_1607.c", "northwest",
        AREA_PATH + "forest_1608.c", "north",
        AREA_PATH + "forest_1609.c", "northeast",
        AREA_PATH + "forest_1657.c", "west",
        AREA_PATH + "forest_1659.c", "east",
        AREA_PATH + "forest_1707.c", "southwest",
        AREA_PATH + "forest_1708.c", "south",
        AREA_PATH + "forest_1709.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1658 ) );
}

