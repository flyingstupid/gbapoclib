/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2209) );
    set_long( get_long_by_id(2209) );


    set_exits(({
        AREA_PATH + "forest_2158.c", "northwest",
        AREA_PATH + "forest_2159.c", "north",
        AREA_PATH + "forest_2160.c", "northeast",
        AREA_PATH + "forest_2208.c", "west",
        AREA_PATH + "forest_2210.c", "east",
        AREA_PATH + "forest_2258.c", "southwest",
        AREA_PATH + "forest_2259.c", "south",
        AREA_PATH + "forest_2260.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2209 ) );
}

