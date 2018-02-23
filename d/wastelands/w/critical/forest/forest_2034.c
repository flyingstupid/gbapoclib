/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2034) );
    set_long( get_long_by_id(2034) );


    set_exits(({
        AREA_PATH + "forest_1983.c", "northwest",
        AREA_PATH + "forest_1984.c", "north",
        AREA_PATH + "forest_1985.c", "northeast",
        AREA_PATH + "forest_2033.c", "west",
        AREA_PATH + "forest_2035.c", "east",
        AREA_PATH + "forest_2083.c", "southwest",
        AREA_PATH + "forest_2084.c", "south",
        AREA_PATH + "forest_2085.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2034 ) );
}

