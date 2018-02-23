/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2001) );
    set_long( get_long_by_id(2001) );


    set_exits(({
        AREA_PATH + "forest_1950.c", "northwest",
        AREA_PATH + "forest_1951.c", "north",
        AREA_PATH + "forest_1952.c", "northeast",
        AREA_PATH + "forest_2000.c", "west",
        AREA_PATH + "forest_2002.c", "east",
        AREA_PATH + "forest_2050.c", "southwest",
        AREA_PATH + "forest_2051.c", "south",
        AREA_PATH + "forest_2052.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2001 ) );
}

