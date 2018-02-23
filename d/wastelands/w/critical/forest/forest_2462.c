/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2462) );
    set_long( get_long_by_id(2462) );


    set_exits(({
        AREA_PATH + "forest_2411.c", "northwest",
        AREA_PATH + "forest_2412.c", "north",
        AREA_PATH + "forest_2413.c", "northeast",
        AREA_PATH + "forest_2461.c", "west",
        AREA_PATH + "forest_2463.c", "east",
    }));

    set_room_type( get_room_scav_type( "forest", 2462 ) );
}

