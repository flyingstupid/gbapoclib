/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2412) );
    set_long( get_long_by_id(2412) );


    set_exits(({
        AREA_PATH + "forest_2361.c", "northwest",
        AREA_PATH + "forest_2362.c", "north",
        AREA_PATH + "forest_2363.c", "northeast",
        AREA_PATH + "forest_2411.c", "west",
        AREA_PATH + "forest_2413.c", "east",
        AREA_PATH + "forest_2461.c", "southwest",
        AREA_PATH + "forest_2462.c", "south",
        AREA_PATH + "forest_2463.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2412 ) );
}

