/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(974) );
    set_long( get_long_by_id(974) );


    set_exits(({
        AREA_PATH + "forest_923.c", "northwest",
        AREA_PATH + "forest_924.c", "north",
        AREA_PATH + "forest_925.c", "northeast",
        AREA_PATH + "forest_973.c", "west",
        AREA_PATH + "forest_975.c", "east",
        AREA_PATH + "forest_1023.c", "southwest",
        AREA_PATH + "forest_1024.c", "south",
        AREA_PATH + "forest_1025.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 974 ) );
}

