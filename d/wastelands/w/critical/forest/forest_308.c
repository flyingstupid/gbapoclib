/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(308) );
    set_long( get_long_by_id(308) );


    set_exits(({
        AREA_PATH + "forest_257.c", "northwest",
        AREA_PATH + "forest_258.c", "north",
        AREA_PATH + "forest_259.c", "northeast",
        AREA_PATH + "forest_307.c", "west",
        AREA_PATH + "forest_309.c", "east",
        AREA_PATH + "forest_357.c", "southwest",
        AREA_PATH + "forest_358.c", "south",
        AREA_PATH + "forest_359.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 308 ) );
}

