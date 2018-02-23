/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2316) );
    set_long( get_long_by_id(2316) );


    set_exits(({
        AREA_PATH + "forest_2265.c", "northwest",
        AREA_PATH + "forest_2266.c", "north",
        AREA_PATH + "forest_2267.c", "northeast",
        AREA_PATH + "forest_2315.c", "west",
        AREA_PATH + "forest_2317.c", "east",
        AREA_PATH + "forest_2365.c", "southwest",
        AREA_PATH + "forest_2366.c", "south",
        AREA_PATH + "forest_2367.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2316 ) );
}

