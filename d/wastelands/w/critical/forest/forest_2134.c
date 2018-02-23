/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2134) );
    set_long( get_long_by_id(2134) );


    set_exits(({
        AREA_PATH + "forest_2083.c", "northwest",
        AREA_PATH + "forest_2084.c", "north",
        AREA_PATH + "forest_2085.c", "northeast",
        AREA_PATH + "forest_2133.c", "west",
        AREA_PATH + "forest_2135.c", "east",
        AREA_PATH + "forest_2183.c", "southwest",
        AREA_PATH + "forest_2184.c", "south",
        AREA_PATH + "forest_2185.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2134 ) );
}

