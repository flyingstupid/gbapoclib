/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1461) );
    set_long( get_long_by_id(1461) );


    set_exits(({
        AREA_PATH + "forest_1410.c", "northwest",
        AREA_PATH + "forest_1411.c", "north",
        AREA_PATH + "forest_1412.c", "northeast",
        AREA_PATH + "forest_1460.c", "west",
        AREA_PATH + "forest_1462.c", "east",
        AREA_PATH + "forest_1510.c", "southwest",
        AREA_PATH + "forest_1511.c", "south",
        AREA_PATH + "forest_1512.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1461 ) );
}

