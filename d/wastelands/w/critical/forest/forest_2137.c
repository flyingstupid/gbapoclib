/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2137) );
    set_long( get_long_by_id(2137) );


    set_exits(({
        AREA_PATH + "forest_2086.c", "northwest",
        AREA_PATH + "forest_2087.c", "north",
        AREA_PATH + "forest_2088.c", "northeast",
        AREA_PATH + "forest_2136.c", "west",
        AREA_PATH + "forest_2138.c", "east",
        AREA_PATH + "forest_2186.c", "southwest",
        AREA_PATH + "forest_2187.c", "south",
        AREA_PATH + "forest_2188.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2137 ) );
}

