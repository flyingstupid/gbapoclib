/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1950) );
    set_long( get_long_by_id(1950) );


    set_exits(({
        AREA_PATH + "forest_1900.c", "north",
        AREA_PATH + "forest_1901.c", "northeast",
        AREA_PATH + "forest_1951.c", "east",
        AREA_PATH + "forest_2000.c", "south",
        AREA_PATH + "forest_2001.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1950 ) );
}

