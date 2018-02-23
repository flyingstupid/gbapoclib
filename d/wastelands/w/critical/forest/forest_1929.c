/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1929) );
    set_long( get_long_by_id(1929) );


    set_exits(({
        AREA_PATH + "forest_1878.c", "northwest",
        AREA_PATH + "forest_1879.c", "north",
        AREA_PATH + "forest_1880.c", "northeast",
        AREA_PATH + "forest_1928.c", "west",
        AREA_PATH + "forest_1930.c", "east",
        AREA_PATH + "forest_1978.c", "southwest",
        AREA_PATH + "forest_1979.c", "south",
        AREA_PATH + "forest_1980.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1929 ) );
}

