/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(584) );
    set_long( get_long_by_id(584) );


    set_exits(({
        AREA_PATH + "forest_533.c", "northwest",
        AREA_PATH + "forest_534.c", "north",
        AREA_PATH + "forest_535.c", "northeast",
        AREA_PATH + "forest_583.c", "west",
        AREA_PATH + "forest_585.c", "east",
        AREA_PATH + "forest_633.c", "southwest",
        AREA_PATH + "forest_634.c", "south",
        AREA_PATH + "forest_635.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 584 ) );
}

