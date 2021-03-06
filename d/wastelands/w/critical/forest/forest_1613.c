/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1613) );
    set_long( get_long_by_id(1613) );


    set_exits(({
        AREA_PATH + "forest_1562.c", "northwest",
        AREA_PATH + "forest_1563.c", "north",
        AREA_PATH + "forest_1564.c", "northeast",
        AREA_PATH + "forest_1612.c", "west",
        AREA_PATH + "forest_1614.c", "east",
        AREA_PATH + "forest_1662.c", "southwest",
        AREA_PATH + "forest_1663.c", "south",
        AREA_PATH + "forest_1664.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1613 ) );
}

