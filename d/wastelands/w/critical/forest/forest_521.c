/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(521) );
    set_long( get_long_by_id(521) );


    set_exits(({
        AREA_PATH + "forest_470.c", "northwest",
        AREA_PATH + "forest_471.c", "north",
        AREA_PATH + "forest_472.c", "northeast",
        AREA_PATH + "forest_520.c", "west",
        AREA_PATH + "forest_522.c", "east",
        AREA_PATH + "forest_570.c", "southwest",
        AREA_PATH + "forest_571.c", "south",
        AREA_PATH + "forest_572.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 521 ) );
}

