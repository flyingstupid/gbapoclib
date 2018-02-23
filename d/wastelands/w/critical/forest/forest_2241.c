/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2241) );
    set_long( get_long_by_id(2241) );


    set_exits(({
        AREA_PATH + "forest_2190.c", "northwest",
        AREA_PATH + "forest_2191.c", "north",
        AREA_PATH + "forest_2192.c", "northeast",
        AREA_PATH + "forest_2240.c", "west",
        AREA_PATH + "forest_2242.c", "east",
        AREA_PATH + "forest_2290.c", "southwest",
        AREA_PATH + "forest_2291.c", "south",
        AREA_PATH + "forest_2292.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2241 ) );
}

