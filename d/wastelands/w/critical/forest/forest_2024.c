/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2024) );
    set_long( get_long_by_id(2024) );


    set_exits(({
        AREA_PATH + "forest_1973.c", "northwest",
        AREA_PATH + "forest_1974.c", "north",
        AREA_PATH + "forest_1975.c", "northeast",
        AREA_PATH + "forest_2023.c", "west",
        AREA_PATH + "forest_2025.c", "east",
        AREA_PATH + "forest_2073.c", "southwest",
        AREA_PATH + "forest_2074.c", "south",
        AREA_PATH + "forest_2075.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2024 ) );
}

