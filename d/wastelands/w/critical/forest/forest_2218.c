/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2218) );
    set_long( get_long_by_id(2218) );


    set_exits(({
        AREA_PATH + "forest_2167.c", "northwest",
        AREA_PATH + "forest_2168.c", "north",
        AREA_PATH + "forest_2169.c", "northeast",
        AREA_PATH + "forest_2217.c", "west",
        AREA_PATH + "forest_2219.c", "east",
        AREA_PATH + "forest_2267.c", "southwest",
        AREA_PATH + "forest_2268.c", "south",
        AREA_PATH + "forest_2269.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2218 ) );
}

