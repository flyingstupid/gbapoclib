/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1977) );
    set_long( get_long_by_id(1977) );


    set_exits(({
        AREA_PATH + "forest_1926.c", "northwest",
        AREA_PATH + "forest_1927.c", "north",
        AREA_PATH + "forest_1928.c", "northeast",
        AREA_PATH + "forest_1976.c", "west",
        AREA_PATH + "forest_1978.c", "east",
        AREA_PATH + "forest_2026.c", "southwest",
        AREA_PATH + "forest_2027.c", "south",
        AREA_PATH + "forest_2028.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1977 ) );
}

