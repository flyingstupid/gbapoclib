/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1905) );
    set_long( get_long_by_id(1905) );


    set_exits(({
        AREA_PATH + "forest_1854.c", "northwest",
        AREA_PATH + "forest_1855.c", "north",
        AREA_PATH + "forest_1856.c", "northeast",
        AREA_PATH + "forest_1904.c", "west",
        AREA_PATH + "forest_1906.c", "east",
        AREA_PATH + "forest_1954.c", "southwest",
        AREA_PATH + "forest_1955.c", "south",
        AREA_PATH + "forest_1956.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1905 ) );
}

