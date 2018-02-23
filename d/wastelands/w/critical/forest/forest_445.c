/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(445) );
    set_long( get_long_by_id(445) );


    set_exits(({
        AREA_PATH + "forest_394.c", "northwest",
        AREA_PATH + "forest_395.c", "north",
        AREA_PATH + "forest_396.c", "northeast",
        AREA_PATH + "forest_444.c", "west",
        AREA_PATH + "forest_446.c", "east",
        AREA_PATH + "forest_494.c", "southwest",
        AREA_PATH + "forest_495.c", "south",
        AREA_PATH + "forest_496.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 445 ) );
}

