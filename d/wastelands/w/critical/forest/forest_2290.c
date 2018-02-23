/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2290) );
    set_long( get_long_by_id(2290) );


    set_exits(({
        AREA_PATH + "forest_2239.c", "northwest",
        AREA_PATH + "forest_2240.c", "north",
        AREA_PATH + "forest_2241.c", "northeast",
        AREA_PATH + "forest_2289.c", "west",
        AREA_PATH + "forest_2291.c", "east",
        AREA_PATH + "forest_2339.c", "southwest",
        AREA_PATH + "forest_2340.c", "south",
        AREA_PATH + "forest_2341.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2290 ) );
}

