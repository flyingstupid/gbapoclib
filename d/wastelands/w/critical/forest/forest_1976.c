/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1976) );
    set_long( get_long_by_id(1976) );


    set_exits(({
        AREA_PATH + "forest_1925.c", "northwest",
        AREA_PATH + "forest_1926.c", "north",
        AREA_PATH + "forest_1927.c", "northeast",
        AREA_PATH + "forest_1975.c", "west",
        AREA_PATH + "forest_1977.c", "east",
        AREA_PATH + "forest_2025.c", "southwest",
        AREA_PATH + "forest_2026.c", "south",
        AREA_PATH + "forest_2027.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1976 ) );
}

