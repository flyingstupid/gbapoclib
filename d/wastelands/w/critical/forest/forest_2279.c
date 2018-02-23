/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2279) );
    set_long( get_long_by_id(2279) );


    set_exits(({
        AREA_PATH + "forest_2228.c", "northwest",
        AREA_PATH + "forest_2229.c", "north",
        AREA_PATH + "forest_2230.c", "northeast",
        AREA_PATH + "forest_2278.c", "west",
        AREA_PATH + "forest_2280.c", "east",
        AREA_PATH + "forest_2328.c", "southwest",
        AREA_PATH + "forest_2329.c", "south",
        AREA_PATH + "forest_2330.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2279 ) );
}

