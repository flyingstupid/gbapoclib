/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2358) );
    set_long( get_long_by_id(2358) );


    set_exits(({
        AREA_PATH + "forest_2307.c", "northwest",
        AREA_PATH + "forest_2308.c", "north",
        AREA_PATH + "forest_2309.c", "northeast",
        AREA_PATH + "forest_2357.c", "west",
        AREA_PATH + "forest_2359.c", "east",
        AREA_PATH + "forest_2407.c", "southwest",
        AREA_PATH + "forest_2408.c", "south",
        AREA_PATH + "forest_2409.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2358 ) );
}

