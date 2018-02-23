/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1458) );
    set_long( get_long_by_id(1458) );


    set_exits(({
        AREA_PATH + "forest_1407.c", "northwest",
        AREA_PATH + "forest_1408.c", "north",
        AREA_PATH + "forest_1409.c", "northeast",
        AREA_PATH + "forest_1457.c", "west",
        AREA_PATH + "forest_1459.c", "east",
        AREA_PATH + "forest_1507.c", "southwest",
        AREA_PATH + "forest_1508.c", "south",
        AREA_PATH + "forest_1509.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1458 ) );
}

