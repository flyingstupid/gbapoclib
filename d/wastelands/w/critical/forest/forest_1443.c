/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1443) );
    set_long( get_long_by_id(1443) );


    set_exits(({
        AREA_PATH + "forest_1392.c", "northwest",
        AREA_PATH + "forest_1393.c", "north",
        AREA_PATH + "forest_1394.c", "northeast",
        AREA_PATH + "forest_1442.c", "west",
        AREA_PATH + "forest_1444.c", "east",
        AREA_PATH + "forest_1492.c", "southwest",
        AREA_PATH + "forest_1493.c", "south",
        AREA_PATH + "forest_1494.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1443 ) );
}

