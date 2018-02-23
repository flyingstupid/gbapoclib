/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1542) );
    set_long( get_long_by_id(1542) );


    set_exits(({
        AREA_PATH + "forest_1491.c", "northwest",
        AREA_PATH + "forest_1492.c", "north",
        AREA_PATH + "forest_1493.c", "northeast",
        AREA_PATH + "forest_1541.c", "west",
        AREA_PATH + "forest_1543.c", "east",
        AREA_PATH + "forest_1591.c", "southwest",
        AREA_PATH + "forest_1592.c", "south",
        AREA_PATH + "forest_1593.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1542 ) );
}

