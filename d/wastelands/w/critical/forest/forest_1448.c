/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1448) );
    set_long( get_long_by_id(1448) );


    set_exits(({
        AREA_PATH + "forest_1397.c", "northwest",
        AREA_PATH + "forest_1398.c", "north",
        AREA_PATH + "forest_1399.c", "northeast",
        AREA_PATH + "forest_1447.c", "west",
        AREA_PATH + "forest_1449.c", "east",
        AREA_PATH + "forest_1497.c", "southwest",
        AREA_PATH + "forest_1498.c", "south",
        AREA_PATH + "forest_1499.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1448 ) );
}

