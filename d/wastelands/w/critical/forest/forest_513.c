/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(513) );
    set_long( get_long_by_id(513) );


    set_exits(({
        AREA_PATH + "forest_462.c", "northwest",
        AREA_PATH + "forest_463.c", "north",
        AREA_PATH + "forest_464.c", "northeast",
        AREA_PATH + "forest_512.c", "west",
        AREA_PATH + "forest_514.c", "east",
        AREA_PATH + "forest_562.c", "southwest",
        AREA_PATH + "forest_563.c", "south",
        AREA_PATH + "forest_564.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 513 ) );
}

