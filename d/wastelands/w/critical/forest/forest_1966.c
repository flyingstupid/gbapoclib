/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1966) );
    set_long( get_long_by_id(1966) );


    set_exits(({
        AREA_PATH + "forest_1915.c", "northwest",
        AREA_PATH + "forest_1916.c", "north",
        AREA_PATH + "forest_1917.c", "northeast",
        AREA_PATH + "forest_1965.c", "west",
        AREA_PATH + "forest_1967.c", "east",
        AREA_PATH + "forest_2015.c", "southwest",
        AREA_PATH + "forest_2016.c", "south",
        AREA_PATH + "forest_2017.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1966 ) );
}

