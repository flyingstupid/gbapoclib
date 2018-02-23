/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1498) );
    set_long( get_long_by_id(1498) );


    set_exits(({
        AREA_PATH + "forest_1447.c", "northwest",
        AREA_PATH + "forest_1448.c", "north",
        AREA_PATH + "forest_1449.c", "northeast",
        AREA_PATH + "forest_1497.c", "west",
        AREA_PATH + "forest_1499.c", "east",
        AREA_PATH + "forest_1547.c", "southwest",
        AREA_PATH + "forest_1548.c", "south",
        AREA_PATH + "forest_1549.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1498 ) );
}

