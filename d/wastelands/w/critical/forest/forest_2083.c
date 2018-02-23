/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2083) );
    set_long( get_long_by_id(2083) );


    set_exits(({
        AREA_PATH + "forest_2032.c", "northwest",
        AREA_PATH + "forest_2033.c", "north",
        AREA_PATH + "forest_2034.c", "northeast",
        AREA_PATH + "forest_2082.c", "west",
        AREA_PATH + "forest_2084.c", "east",
        AREA_PATH + "forest_2132.c", "southwest",
        AREA_PATH + "forest_2133.c", "south",
        AREA_PATH + "forest_2134.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2083 ) );
}

