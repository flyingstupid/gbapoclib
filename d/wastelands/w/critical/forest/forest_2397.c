/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2397) );
    set_long( get_long_by_id(2397) );


    set_exits(({
        AREA_PATH + "forest_2346.c", "northwest",
        AREA_PATH + "forest_2347.c", "north",
        AREA_PATH + "forest_2348.c", "northeast",
        AREA_PATH + "forest_2396.c", "west",
        AREA_PATH + "forest_2398.c", "east",
        AREA_PATH + "forest_2446.c", "southwest",
        AREA_PATH + "forest_2447.c", "south",
        AREA_PATH + "forest_2448.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2397 ) );
}

