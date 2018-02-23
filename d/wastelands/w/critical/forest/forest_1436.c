/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1436) );
    set_long( get_long_by_id(1436) );


    set_exits(({
        AREA_PATH + "forest_1385.c", "northwest",
        AREA_PATH + "forest_1386.c", "north",
        AREA_PATH + "forest_1387.c", "northeast",
        AREA_PATH + "forest_1435.c", "west",
        AREA_PATH + "forest_1437.c", "east",
        AREA_PATH + "forest_1485.c", "southwest",
        AREA_PATH + "forest_1486.c", "south",
        AREA_PATH + "forest_1487.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1436 ) );
}

