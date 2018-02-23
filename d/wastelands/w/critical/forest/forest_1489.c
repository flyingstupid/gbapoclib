/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1489) );
    set_long( get_long_by_id(1489) );


    set_exits(({
        AREA_PATH + "forest_1438.c", "northwest",
        AREA_PATH + "forest_1439.c", "north",
        AREA_PATH + "forest_1440.c", "northeast",
        AREA_PATH + "forest_1488.c", "west",
        AREA_PATH + "forest_1490.c", "east",
        AREA_PATH + "forest_1538.c", "southwest",
        AREA_PATH + "forest_1539.c", "south",
        AREA_PATH + "forest_1540.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1489 ) );
}

