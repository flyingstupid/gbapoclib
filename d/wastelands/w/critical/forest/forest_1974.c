/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1974) );
    set_long( get_long_by_id(1974) );


    set_exits(({
        AREA_PATH + "forest_1923.c", "northwest",
        AREA_PATH + "forest_1924.c", "north",
        AREA_PATH + "forest_1925.c", "northeast",
        AREA_PATH + "forest_1973.c", "west",
        AREA_PATH + "forest_1975.c", "east",
        AREA_PATH + "forest_2023.c", "southwest",
        AREA_PATH + "forest_2024.c", "south",
        AREA_PATH + "forest_2025.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1974 ) );
}

