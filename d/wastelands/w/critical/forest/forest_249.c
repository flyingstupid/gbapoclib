/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(249) );
    set_long( get_long_by_id(249) );


    set_exits(({
        AREA_PATH + "forest_198.c", "northwest",
        AREA_PATH + "forest_199.c", "north",
        AREA_PATH + "forest_248.c", "west",
        AREA_PATH + "forest_298.c", "southwest",
        AREA_PATH + "forest_299.c", "south",
    }));

    set_room_type( get_room_scav_type( "forest", 249 ) );
}

