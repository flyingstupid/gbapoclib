/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2073) );
    set_long( get_long_by_id(2073) );


    set_exits(({
        AREA_PATH + "forest_2022.c", "northwest",
        AREA_PATH + "forest_2023.c", "north",
        AREA_PATH + "forest_2024.c", "northeast",
        AREA_PATH + "forest_2072.c", "west",
        AREA_PATH + "forest_2074.c", "east",
        AREA_PATH + "forest_2122.c", "southwest",
        AREA_PATH + "forest_2123.c", "south",
        AREA_PATH + "forest_2124.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2073 ) );
}

