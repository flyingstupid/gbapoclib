/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1518) );
    set_long( get_long_by_id(1518) );


    set_exits(({
        AREA_PATH + "forest_1467.c", "northwest",
        AREA_PATH + "forest_1468.c", "north",
        AREA_PATH + "forest_1469.c", "northeast",
        AREA_PATH + "forest_1517.c", "west",
        AREA_PATH + "forest_1519.c", "east",
        AREA_PATH + "forest_1567.c", "southwest",
        AREA_PATH + "forest_1568.c", "south",
        AREA_PATH + "forest_1569.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1518 ) );
}

