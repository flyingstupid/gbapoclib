/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2286) );
    set_long( get_long_by_id(2286) );


    set_exits(({
        AREA_PATH + "forest_2235.c", "northwest",
        AREA_PATH + "forest_2236.c", "north",
        AREA_PATH + "forest_2237.c", "northeast",
        AREA_PATH + "forest_2285.c", "west",
        AREA_PATH + "forest_2287.c", "east",
        AREA_PATH + "forest_2335.c", "southwest",
        AREA_PATH + "forest_2336.c", "south",
        AREA_PATH + "forest_2337.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2286 ) );
}

