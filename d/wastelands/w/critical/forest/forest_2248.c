/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2248) );
    set_long( get_long_by_id(2248) );


    set_exits(({
        AREA_PATH + "forest_2197.c", "northwest",
        AREA_PATH + "forest_2198.c", "north",
        AREA_PATH + "forest_2199.c", "northeast",
        AREA_PATH + "forest_2247.c", "west",
        AREA_PATH + "forest_2249.c", "east",
        AREA_PATH + "forest_2297.c", "southwest",
        AREA_PATH + "forest_2298.c", "south",
        AREA_PATH + "forest_2299.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2248 ) );
}

