/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1709) );
    set_long( get_long_by_id(1709) );


    set_exits(({
        AREA_PATH + "forest_1658.c", "northwest",
        AREA_PATH + "forest_1659.c", "north",
        AREA_PATH + "forest_1660.c", "northeast",
        AREA_PATH + "forest_1708.c", "west",
        AREA_PATH + "forest_1710.c", "east",
        AREA_PATH + "forest_1758.c", "southwest",
        AREA_PATH + "forest_1759.c", "south",
        AREA_PATH + "forest_1760.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1709 ) );
}

