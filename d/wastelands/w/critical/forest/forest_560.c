/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(560) );
    set_long( get_long_by_id(560) );


    set_exits(({
        AREA_PATH + "forest_509.c", "northwest",
        AREA_PATH + "forest_510.c", "north",
        AREA_PATH + "forest_511.c", "northeast",
        AREA_PATH + "forest_559.c", "west",
        AREA_PATH + "forest_561.c", "east",
        AREA_PATH + "forest_609.c", "southwest",
        AREA_PATH + "forest_610.c", "south",
        AREA_PATH + "forest_611.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 560 ) );
}

