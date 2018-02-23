/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2200) );
    set_long( get_long_by_id(2200) );


    set_exits(({
        AREA_PATH + "forest_2150.c", "north",
        AREA_PATH + "forest_2151.c", "northeast",
        AREA_PATH + "forest_2201.c", "east",
        AREA_PATH + "forest_2250.c", "south",
        AREA_PATH + "forest_2251.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2200 ) );
}

