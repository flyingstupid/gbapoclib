/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(334) );
    set_long( get_long_by_id(334) );


    set_exits(({
        AREA_PATH + "forest_283.c", "northwest",
        AREA_PATH + "forest_284.c", "north",
        AREA_PATH + "forest_285.c", "northeast",
        AREA_PATH + "forest_333.c", "west",
        AREA_PATH + "forest_335.c", "east",
        AREA_PATH + "forest_383.c", "southwest",
        AREA_PATH + "forest_384.c", "south",
        AREA_PATH + "forest_385.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 334 ) );
}

