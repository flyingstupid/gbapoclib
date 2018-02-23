/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2116) );
    set_long( get_long_by_id(2116) );


    set_exits(({
        AREA_PATH + "forest_2065.c", "northwest",
        AREA_PATH + "forest_2066.c", "north",
        AREA_PATH + "forest_2067.c", "northeast",
        AREA_PATH + "forest_2115.c", "west",
        AREA_PATH + "forest_2117.c", "east",
        AREA_PATH + "forest_2165.c", "southwest",
        AREA_PATH + "forest_2166.c", "south",
        AREA_PATH + "forest_2167.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2116 ) );
}

