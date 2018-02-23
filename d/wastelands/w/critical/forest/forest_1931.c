/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1931) );
    set_long( get_long_by_id(1931) );


    set_exits(({
        AREA_PATH + "forest_1880.c", "northwest",
        AREA_PATH + "forest_1881.c", "north",
        AREA_PATH + "forest_1882.c", "northeast",
        AREA_PATH + "forest_1930.c", "west",
        AREA_PATH + "forest_1932.c", "east",
        AREA_PATH + "forest_1980.c", "southwest",
        AREA_PATH + "forest_1981.c", "south",
        AREA_PATH + "forest_1982.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1931 ) );
}

