/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2121) );
    set_long( get_long_by_id(2121) );


    set_exits(({
        AREA_PATH + "forest_2070.c", "northwest",
        AREA_PATH + "forest_2071.c", "north",
        AREA_PATH + "forest_2072.c", "northeast",
        AREA_PATH + "forest_2120.c", "west",
        AREA_PATH + "forest_2122.c", "east",
        AREA_PATH + "forest_2170.c", "southwest",
        AREA_PATH + "forest_2171.c", "south",
        AREA_PATH + "forest_2172.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2121 ) );
}

