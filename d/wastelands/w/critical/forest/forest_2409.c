/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2409) );
    set_long( get_long_by_id(2409) );


    set_exits(({
        AREA_PATH + "forest_2358.c", "northwest",
        AREA_PATH + "forest_2359.c", "north",
        AREA_PATH + "forest_2360.c", "northeast",
        AREA_PATH + "forest_2408.c", "west",
        AREA_PATH + "forest_2410.c", "east",
        AREA_PATH + "forest_2458.c", "southwest",
        AREA_PATH + "forest_2459.c", "south",
        AREA_PATH + "forest_2460.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2409 ) );
}

