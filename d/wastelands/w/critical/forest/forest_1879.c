/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1879) );
    set_long( get_long_by_id(1879) );


    set_exits(({
        AREA_PATH + "forest_1828.c", "northwest",
        AREA_PATH + "forest_1829.c", "north",
        AREA_PATH + "forest_1830.c", "northeast",
        AREA_PATH + "forest_1878.c", "west",
        AREA_PATH + "forest_1880.c", "east",
        AREA_PATH + "forest_1928.c", "southwest",
        AREA_PATH + "forest_1929.c", "south",
        AREA_PATH + "forest_1930.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1879 ) );
}

