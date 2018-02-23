/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2045) );
    set_long( get_long_by_id(2045) );


    set_exits(({
        AREA_PATH + "forest_1994.c", "northwest",
        AREA_PATH + "forest_1995.c", "north",
        AREA_PATH + "forest_1996.c", "northeast",
        AREA_PATH + "forest_2044.c", "west",
        AREA_PATH + "forest_2046.c", "east",
        AREA_PATH + "forest_2094.c", "southwest",
        AREA_PATH + "forest_2095.c", "south",
        AREA_PATH + "forest_2096.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2045 ) );
}

