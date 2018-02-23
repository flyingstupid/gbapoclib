/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1536) );
    set_long( get_long_by_id(1536) );


    set_exits(({
        AREA_PATH + "forest_1485.c", "northwest",
        AREA_PATH + "forest_1486.c", "north",
        AREA_PATH + "forest_1487.c", "northeast",
        AREA_PATH + "forest_1535.c", "west",
        AREA_PATH + "forest_1537.c", "east",
        AREA_PATH + "forest_1585.c", "southwest",
        AREA_PATH + "forest_1586.c", "south",
        AREA_PATH + "forest_1587.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1536 ) );
}

