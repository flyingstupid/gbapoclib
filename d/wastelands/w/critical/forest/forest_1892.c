/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1892) );
    set_long( get_long_by_id(1892) );


    set_exits(({
        AREA_PATH + "forest_1841.c", "northwest",
        AREA_PATH + "forest_1842.c", "north",
        AREA_PATH + "forest_1843.c", "northeast",
        AREA_PATH + "forest_1891.c", "west",
        AREA_PATH + "forest_1893.c", "east",
        AREA_PATH + "forest_1941.c", "southwest",
        AREA_PATH + "forest_1942.c", "south",
        AREA_PATH + "forest_1943.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1892 ) );
}

