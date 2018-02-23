/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(411) );
    set_long( get_long_by_id(411) );


    set_exits(({
        AREA_PATH + "forest_360.c", "northwest",
        AREA_PATH + "forest_361.c", "north",
        AREA_PATH + "forest_362.c", "northeast",
        AREA_PATH + "forest_410.c", "west",
        AREA_PATH + "forest_412.c", "east",
        AREA_PATH + "forest_460.c", "southwest",
        AREA_PATH + "forest_461.c", "south",
        AREA_PATH + "forest_462.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 411 ) );
}

