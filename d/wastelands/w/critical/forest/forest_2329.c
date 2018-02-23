/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2329) );
    set_long( get_long_by_id(2329) );


    set_exits(({
        AREA_PATH + "forest_2278.c", "northwest",
        AREA_PATH + "forest_2279.c", "north",
        AREA_PATH + "forest_2280.c", "northeast",
        AREA_PATH + "forest_2328.c", "west",
        AREA_PATH + "forest_2330.c", "east",
        AREA_PATH + "forest_2378.c", "southwest",
        AREA_PATH + "forest_2379.c", "south",
        AREA_PATH + "forest_2380.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2329 ) );
}

