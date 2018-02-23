/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(547) );
    set_long( get_long_by_id(547) );


    set_exits(({
        AREA_PATH + "forest_496.c", "northwest",
        AREA_PATH + "forest_497.c", "north",
        AREA_PATH + "forest_498.c", "northeast",
        AREA_PATH + "forest_546.c", "west",
        AREA_PATH + "forest_548.c", "east",
        AREA_PATH + "forest_596.c", "southwest",
        AREA_PATH + "forest_597.c", "south",
        AREA_PATH + "forest_598.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 547 ) );
}

