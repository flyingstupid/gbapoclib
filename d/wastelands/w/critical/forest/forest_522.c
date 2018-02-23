/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(522) );
    set_long( get_long_by_id(522) );


    set_exits(({
        AREA_PATH + "forest_471.c", "northwest",
        AREA_PATH + "forest_472.c", "north",
        AREA_PATH + "forest_473.c", "northeast",
        AREA_PATH + "forest_521.c", "west",
        AREA_PATH + "forest_523.c", "east",
        AREA_PATH + "forest_571.c", "southwest",
        AREA_PATH + "forest_572.c", "south",
        AREA_PATH + "forest_573.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 522 ) );
}

