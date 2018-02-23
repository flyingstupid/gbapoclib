/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1890) );
    set_long( get_long_by_id(1890) );


    set_exits(({
        AREA_PATH + "forest_1839.c", "northwest",
        AREA_PATH + "forest_1840.c", "north",
        AREA_PATH + "forest_1841.c", "northeast",
        AREA_PATH + "forest_1889.c", "west",
        AREA_PATH + "forest_1891.c", "east",
        AREA_PATH + "forest_1939.c", "southwest",
        AREA_PATH + "forest_1940.c", "south",
        AREA_PATH + "forest_1941.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1890 ) );
}

