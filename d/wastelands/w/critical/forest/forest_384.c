/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(384) );
    set_long( get_long_by_id(384) );


    set_exits(({
        AREA_PATH + "forest_333.c", "northwest",
        AREA_PATH + "forest_334.c", "north",
        AREA_PATH + "forest_335.c", "northeast",
        AREA_PATH + "forest_383.c", "west",
        AREA_PATH + "forest_385.c", "east",
        AREA_PATH + "forest_433.c", "southwest",
        AREA_PATH + "forest_434.c", "south",
        AREA_PATH + "forest_435.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 384 ) );
}

