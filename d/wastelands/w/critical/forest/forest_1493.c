/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1493) );
    set_long( get_long_by_id(1493) );


    set_exits(({
        AREA_PATH + "forest_1442.c", "northwest",
        AREA_PATH + "forest_1443.c", "north",
        AREA_PATH + "forest_1444.c", "northeast",
        AREA_PATH + "forest_1492.c", "west",
        AREA_PATH + "forest_1494.c", "east",
        AREA_PATH + "forest_1542.c", "southwest",
        AREA_PATH + "forest_1543.c", "south",
        AREA_PATH + "forest_1544.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1493 ) );
}

