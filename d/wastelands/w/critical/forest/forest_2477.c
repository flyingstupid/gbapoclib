/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2477) );
    set_long( get_long_by_id(2477) );


    set_exits(({
        AREA_PATH + "forest_2426.c", "northwest",
        AREA_PATH + "forest_2427.c", "north",
        AREA_PATH + "forest_2428.c", "northeast",
        AREA_PATH + "forest_2476.c", "west",
        AREA_PATH + "forest_2478.c", "east",
    }));

    set_room_type( get_room_scav_type( "forest", 2477 ) );
}

