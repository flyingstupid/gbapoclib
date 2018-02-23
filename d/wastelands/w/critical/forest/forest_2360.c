/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2360) );
    set_long( get_long_by_id(2360) );


    set_exits(({
        AREA_PATH + "forest_2309.c", "northwest",
        AREA_PATH + "forest_2310.c", "north",
        AREA_PATH + "forest_2311.c", "northeast",
        AREA_PATH + "forest_2359.c", "west",
        AREA_PATH + "forest_2361.c", "east",
        AREA_PATH + "forest_2409.c", "southwest",
        AREA_PATH + "forest_2410.c", "south",
        AREA_PATH + "forest_2411.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2360 ) );
}

