/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2159) );
    set_long( get_long_by_id(2159) );


    set_exits(({
        AREA_PATH + "forest_2108.c", "northwest",
        AREA_PATH + "forest_2109.c", "north",
        AREA_PATH + "forest_2110.c", "northeast",
        AREA_PATH + "forest_2158.c", "west",
        AREA_PATH + "forest_2160.c", "east",
        AREA_PATH + "forest_2208.c", "southwest",
        AREA_PATH + "forest_2209.c", "south",
        AREA_PATH + "forest_2210.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2159 ) );
}

