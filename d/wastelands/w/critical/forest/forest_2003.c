/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2003) );
    set_long( get_long_by_id(2003) );


    set_exits(({
        AREA_PATH + "forest_1952.c", "northwest",
        AREA_PATH + "forest_1953.c", "north",
        AREA_PATH + "forest_1954.c", "northeast",
        AREA_PATH + "forest_2002.c", "west",
        AREA_PATH + "forest_2004.c", "east",
        AREA_PATH + "forest_2052.c", "southwest",
        AREA_PATH + "forest_2053.c", "south",
        AREA_PATH + "forest_2054.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2003 ) );
}

