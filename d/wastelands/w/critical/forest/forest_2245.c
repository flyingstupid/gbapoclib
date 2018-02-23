/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2245) );
    set_long( get_long_by_id(2245) );


    set_exits(({
        AREA_PATH + "forest_2194.c", "northwest",
        AREA_PATH + "forest_2195.c", "north",
        AREA_PATH + "forest_2196.c", "northeast",
        AREA_PATH + "forest_2244.c", "west",
        AREA_PATH + "forest_2246.c", "east",
        AREA_PATH + "forest_2294.c", "southwest",
        AREA_PATH + "forest_2295.c", "south",
        AREA_PATH + "forest_2296.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2245 ) );
}

