/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2362) );
    set_long( get_long_by_id(2362) );


    set_exits(({
        AREA_PATH + "forest_2311.c", "northwest",
        AREA_PATH + "forest_2312.c", "north",
        AREA_PATH + "forest_2313.c", "northeast",
        AREA_PATH + "forest_2361.c", "west",
        AREA_PATH + "forest_2363.c", "east",
        AREA_PATH + "forest_2411.c", "southwest",
        AREA_PATH + "forest_2412.c", "south",
        AREA_PATH + "forest_2413.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2362 ) );
}

