/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(416) );
    set_long( get_long_by_id(416) );


    set_exits(({
        AREA_PATH + "forest_365.c", "northwest",
        AREA_PATH + "forest_366.c", "north",
        AREA_PATH + "forest_367.c", "northeast",
        AREA_PATH + "forest_415.c", "west",
        AREA_PATH + "forest_417.c", "east",
        AREA_PATH + "forest_465.c", "southwest",
        AREA_PATH + "forest_466.c", "south",
        AREA_PATH + "forest_467.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 416 ) );
}

