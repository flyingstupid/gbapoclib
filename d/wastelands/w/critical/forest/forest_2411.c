/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2411) );
    set_long( get_long_by_id(2411) );


    set_exits(({
        AREA_PATH + "forest_2360.c", "northwest",
        AREA_PATH + "forest_2361.c", "north",
        AREA_PATH + "forest_2362.c", "northeast",
        AREA_PATH + "forest_2410.c", "west",
        AREA_PATH + "forest_2412.c", "east",
        AREA_PATH + "forest_2460.c", "southwest",
        AREA_PATH + "forest_2461.c", "south",
        AREA_PATH + "forest_2462.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2411 ) );
}

