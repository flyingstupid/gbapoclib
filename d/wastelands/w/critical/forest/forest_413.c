/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(413) );
    set_long( get_long_by_id(413) );


    set_exits(({
        AREA_PATH + "forest_362.c", "northwest",
        AREA_PATH + "forest_363.c", "north",
        AREA_PATH + "forest_364.c", "northeast",
        AREA_PATH + "forest_412.c", "west",
        AREA_PATH + "forest_414.c", "east",
        AREA_PATH + "forest_462.c", "southwest",
        AREA_PATH + "forest_463.c", "south",
        AREA_PATH + "forest_464.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 413 ) );
}

