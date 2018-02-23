/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1636) );
    set_long( get_long_by_id(1636) );


    set_exits(({
        AREA_PATH + "forest_1585.c", "northwest",
        AREA_PATH + "forest_1586.c", "north",
        AREA_PATH + "forest_1587.c", "northeast",
        AREA_PATH + "forest_1635.c", "west",
        AREA_PATH + "forest_1637.c", "east",
        AREA_PATH + "forest_1685.c", "southwest",
        AREA_PATH + "forest_1686.c", "south",
        AREA_PATH + "forest_1687.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1636 ) );
}

