/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2297) );
    set_long( get_long_by_id(2297) );


    set_exits(({
        AREA_PATH + "forest_2246.c", "northwest",
        AREA_PATH + "forest_2247.c", "north",
        AREA_PATH + "forest_2248.c", "northeast",
        AREA_PATH + "forest_2296.c", "west",
        AREA_PATH + "forest_2298.c", "east",
        AREA_PATH + "forest_2346.c", "southwest",
        AREA_PATH + "forest_2347.c", "south",
        AREA_PATH + "forest_2348.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2297 ) );
}

