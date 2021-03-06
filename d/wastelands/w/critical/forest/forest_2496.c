/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2496) );
    set_long( get_long_by_id(2496) );


    set_exits(({
        AREA_PATH + "forest_2445.c", "northwest",
        AREA_PATH + "forest_2446.c", "north",
        AREA_PATH + "forest_2447.c", "northeast",
        AREA_PATH + "forest_2495.c", "west",
        AREA_PATH + "forest_2497.c", "east",
    }));

    set_room_type( get_room_scav_type( "forest", 2496 ) );
}

