/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1466) );
    set_long( get_long_by_id(1466) );


    set_exits(({
        AREA_PATH + "forest_1415.c", "northwest",
        AREA_PATH + "forest_1416.c", "north",
        AREA_PATH + "forest_1417.c", "northeast",
        AREA_PATH + "forest_1465.c", "west",
        AREA_PATH + "forest_1467.c", "east",
        AREA_PATH + "forest_1515.c", "southwest",
        AREA_PATH + "forest_1516.c", "south",
        AREA_PATH + "forest_1517.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1466 ) );
}

