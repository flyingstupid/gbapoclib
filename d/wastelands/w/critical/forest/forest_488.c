/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(488) );
    set_long( get_long_by_id(488) );


    set_exits(({
        AREA_PATH + "forest_437.c", "northwest",
        AREA_PATH + "forest_438.c", "north",
        AREA_PATH + "forest_439.c", "northeast",
        AREA_PATH + "forest_487.c", "west",
        AREA_PATH + "forest_489.c", "east",
        AREA_PATH + "forest_537.c", "southwest",
        AREA_PATH + "forest_538.c", "south",
        AREA_PATH + "forest_539.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 488 ) );
}

