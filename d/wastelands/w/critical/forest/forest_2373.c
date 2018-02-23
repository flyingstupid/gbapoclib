/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2373) );
    set_long( get_long_by_id(2373) );


    set_exits(({
        AREA_PATH + "forest_2322.c", "northwest",
        AREA_PATH + "forest_2323.c", "north",
        AREA_PATH + "forest_2324.c", "northeast",
        AREA_PATH + "forest_2372.c", "west",
        AREA_PATH + "forest_2374.c", "east",
        AREA_PATH + "forest_2422.c", "southwest",
        AREA_PATH + "forest_2423.c", "south",
        AREA_PATH + "forest_2424.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2373 ) );
}

