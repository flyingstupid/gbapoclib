/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2197) );
    set_long( get_long_by_id(2197) );


    set_exits(({
        AREA_PATH + "forest_2146.c", "northwest",
        AREA_PATH + "forest_2147.c", "north",
        AREA_PATH + "forest_2148.c", "northeast",
        AREA_PATH + "forest_2196.c", "west",
        AREA_PATH + "forest_2198.c", "east",
        AREA_PATH + "forest_2246.c", "southwest",
        AREA_PATH + "forest_2247.c", "south",
        AREA_PATH + "forest_2248.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2197 ) );
}

