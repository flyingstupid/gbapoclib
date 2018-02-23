/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1983) );
    set_long( get_long_by_id(1983) );


    set_exits(({
        AREA_PATH + "forest_1932.c", "northwest",
        AREA_PATH + "forest_1933.c", "north",
        AREA_PATH + "forest_1934.c", "northeast",
        AREA_PATH + "forest_1982.c", "west",
        AREA_PATH + "forest_1984.c", "east",
        AREA_PATH + "forest_2032.c", "southwest",
        AREA_PATH + "forest_2033.c", "south",
        AREA_PATH + "forest_2034.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1983 ) );
}

