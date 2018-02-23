/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1504) );
    set_long( get_long_by_id(1504) );


    set_exits(({
        AREA_PATH + "forest_1453.c", "northwest",
        AREA_PATH + "forest_1454.c", "north",
        AREA_PATH + "forest_1455.c", "northeast",
        AREA_PATH + "forest_1503.c", "west",
        AREA_PATH + "forest_1505.c", "east",
        AREA_PATH + "forest_1553.c", "southwest",
        AREA_PATH + "forest_1554.c", "south",
        AREA_PATH + "forest_1555.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1504 ) );
}

