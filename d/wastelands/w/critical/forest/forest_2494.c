/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2494) );
    set_long( get_long_by_id(2494) );


    set_exits(({
        AREA_PATH + "forest_2443.c", "northwest",
        AREA_PATH + "forest_2444.c", "north",
        AREA_PATH + "forest_2445.c", "northeast",
        AREA_PATH + "forest_2493.c", "west",
        AREA_PATH + "forest_2495.c", "east",
    }));

    set_room_type( get_room_scav_type( "forest", 2494 ) );
}

