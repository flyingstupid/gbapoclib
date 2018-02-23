/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(536) );
    set_long( get_long_by_id(536) );


    set_exits(({
        AREA_PATH + "forest_485.c", "northwest",
        AREA_PATH + "forest_486.c", "north",
        AREA_PATH + "forest_487.c", "northeast",
        AREA_PATH + "forest_535.c", "west",
        AREA_PATH + "forest_537.c", "east",
        AREA_PATH + "forest_585.c", "southwest",
        AREA_PATH + "forest_586.c", "south",
        AREA_PATH + "forest_587.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 536 ) );
}

