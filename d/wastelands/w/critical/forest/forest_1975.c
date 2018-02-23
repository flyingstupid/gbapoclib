/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1975) );
    set_long( get_long_by_id(1975) );


    set_exits(({
        AREA_PATH + "forest_1924.c", "northwest",
        AREA_PATH + "forest_1925.c", "north",
        AREA_PATH + "forest_1926.c", "northeast",
        AREA_PATH + "forest_1974.c", "west",
        AREA_PATH + "forest_1976.c", "east",
        AREA_PATH + "forest_2024.c", "southwest",
        AREA_PATH + "forest_2025.c", "south",
        AREA_PATH + "forest_2026.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1975 ) );
}

