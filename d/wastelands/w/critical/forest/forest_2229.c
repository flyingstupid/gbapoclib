/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2229) );
    set_long( get_long_by_id(2229) );


    set_exits(({
        AREA_PATH + "forest_2178.c", "northwest",
        AREA_PATH + "forest_2179.c", "north",
        AREA_PATH + "forest_2180.c", "northeast",
        AREA_PATH + "forest_2228.c", "west",
        AREA_PATH + "forest_2230.c", "east",
        AREA_PATH + "forest_2278.c", "southwest",
        AREA_PATH + "forest_2279.c", "south",
        AREA_PATH + "forest_2280.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2229 ) );
}

