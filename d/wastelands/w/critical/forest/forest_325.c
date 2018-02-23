/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(325) );
    set_long( get_long_by_id(325) );


    set_exits(({
        AREA_PATH + "forest_274.c", "northwest",
        AREA_PATH + "forest_275.c", "north",
        AREA_PATH + "forest_276.c", "northeast",
        AREA_PATH + "forest_324.c", "west",
        AREA_PATH + "forest_326.c", "east",
        AREA_PATH + "forest_374.c", "southwest",
        AREA_PATH + "forest_375.c", "south",
        AREA_PATH + "forest_376.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 325 ) );
}

