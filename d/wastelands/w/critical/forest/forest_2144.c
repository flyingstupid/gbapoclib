/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2144) );
    set_long( get_long_by_id(2144) );


    set_exits(({
        AREA_PATH + "forest_2093.c", "northwest",
        AREA_PATH + "forest_2094.c", "north",
        AREA_PATH + "forest_2095.c", "northeast",
        AREA_PATH + "forest_2143.c", "west",
        AREA_PATH + "forest_2145.c", "east",
        AREA_PATH + "forest_2193.c", "southwest",
        AREA_PATH + "forest_2194.c", "south",
        AREA_PATH + "forest_2195.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2144 ) );
}

