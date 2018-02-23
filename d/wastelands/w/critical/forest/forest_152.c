/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(152) );
    set_long( get_long_by_id(152) );


    set_exits(({
        AREA_PATH + "forest_101.c", "northwest",
        AREA_PATH + "forest_102.c", "north",
        AREA_PATH + "forest_103.c", "northeast",
        AREA_PATH + "forest_151.c", "west",
        AREA_PATH + "forest_153.c", "east",
        AREA_PATH + "forest_201.c", "southwest",
        AREA_PATH + "forest_202.c", "south",
        AREA_PATH + "forest_203.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 152 ) );
}

