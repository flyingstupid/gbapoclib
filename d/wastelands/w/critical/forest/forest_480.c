/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(480) );
    set_long( get_long_by_id(480) );


    set_exits(({
        AREA_PATH + "forest_429.c", "northwest",
        AREA_PATH + "forest_430.c", "north",
        AREA_PATH + "forest_431.c", "northeast",
        AREA_PATH + "forest_479.c", "west",
        AREA_PATH + "forest_481.c", "east",
        AREA_PATH + "forest_529.c", "southwest",
        AREA_PATH + "forest_530.c", "south",
        AREA_PATH + "forest_531.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 480 ) );
}

