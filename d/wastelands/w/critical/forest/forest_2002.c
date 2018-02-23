/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2002) );
    set_long( get_long_by_id(2002) );


    set_exits(({
        AREA_PATH + "forest_1951.c", "northwest",
        AREA_PATH + "forest_1952.c", "north",
        AREA_PATH + "forest_1953.c", "northeast",
        AREA_PATH + "forest_2001.c", "west",
        AREA_PATH + "forest_2003.c", "east",
        AREA_PATH + "forest_2051.c", "southwest",
        AREA_PATH + "forest_2052.c", "south",
        AREA_PATH + "forest_2053.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2002 ) );
}

