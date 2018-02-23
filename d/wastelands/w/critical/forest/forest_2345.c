/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2345) );
    set_long( get_long_by_id(2345) );


    set_exits(({
        AREA_PATH + "forest_2294.c", "northwest",
        AREA_PATH + "forest_2295.c", "north",
        AREA_PATH + "forest_2296.c", "northeast",
        AREA_PATH + "forest_2344.c", "west",
        AREA_PATH + "forest_2346.c", "east",
        AREA_PATH + "forest_2394.c", "southwest",
        AREA_PATH + "forest_2395.c", "south",
        AREA_PATH + "forest_2396.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2345 ) );
}

