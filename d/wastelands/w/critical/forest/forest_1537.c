/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1537) );
    set_long( get_long_by_id(1537) );


    set_exits(({
        AREA_PATH + "forest_1486.c", "northwest",
        AREA_PATH + "forest_1487.c", "north",
        AREA_PATH + "forest_1488.c", "northeast",
        AREA_PATH + "forest_1536.c", "west",
        AREA_PATH + "forest_1538.c", "east",
        AREA_PATH + "forest_1586.c", "southwest",
        AREA_PATH + "forest_1587.c", "south",
        AREA_PATH + "forest_1588.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1537 ) );
}

