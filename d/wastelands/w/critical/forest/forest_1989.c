/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1989) );
    set_long( get_long_by_id(1989) );


    set_exits(({
        AREA_PATH + "forest_1938.c", "northwest",
        AREA_PATH + "forest_1939.c", "north",
        AREA_PATH + "forest_1940.c", "northeast",
        AREA_PATH + "forest_1988.c", "west",
        AREA_PATH + "forest_1990.c", "east",
        AREA_PATH + "forest_2038.c", "southwest",
        AREA_PATH + "forest_2039.c", "south",
        AREA_PATH + "forest_2040.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1989 ) );
}

