/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(225) );
    set_long( get_long_by_id(225) );


    set_exits(({
        AREA_PATH + "forest_174.c", "northwest",
        AREA_PATH + "forest_175.c", "north",
        AREA_PATH + "forest_176.c", "northeast",
        AREA_PATH + "forest_224.c", "west",
        AREA_PATH + "forest_226.c", "east",
        AREA_PATH + "forest_274.c", "southwest",
        AREA_PATH + "forest_275.c", "south",
        AREA_PATH + "forest_276.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 225 ) );
}

