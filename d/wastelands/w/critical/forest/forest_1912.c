/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1912) );
    set_long( get_long_by_id(1912) );


    set_exits(({
        AREA_PATH + "forest_1861.c", "northwest",
        AREA_PATH + "forest_1862.c", "north",
        AREA_PATH + "forest_1863.c", "northeast",
        AREA_PATH + "forest_1911.c", "west",
        AREA_PATH + "forest_1913.c", "east",
        AREA_PATH + "forest_1961.c", "southwest",
        AREA_PATH + "forest_1962.c", "south",
        AREA_PATH + "forest_1963.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1912 ) );
}

