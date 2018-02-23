/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2403) );
    set_long( get_long_by_id(2403) );


    set_exits(({
        AREA_PATH + "forest_2352.c", "northwest",
        AREA_PATH + "forest_2353.c", "north",
        AREA_PATH + "forest_2354.c", "northeast",
        AREA_PATH + "forest_2402.c", "west",
        AREA_PATH + "forest_2404.c", "east",
        AREA_PATH + "forest_2452.c", "southwest",
        AREA_PATH + "forest_2453.c", "south",
        AREA_PATH + "forest_2454.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2403 ) );
}

