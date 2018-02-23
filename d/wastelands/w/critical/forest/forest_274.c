/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(274) );
    set_long( get_long_by_id(274) );


    set_exits(({
        AREA_PATH + "forest_223.c", "northwest",
        AREA_PATH + "forest_224.c", "north",
        AREA_PATH + "forest_225.c", "northeast",
        AREA_PATH + "forest_273.c", "west",
        AREA_PATH + "forest_275.c", "east",
        AREA_PATH + "forest_323.c", "southwest",
        AREA_PATH + "forest_324.c", "south",
        AREA_PATH + "forest_325.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 274 ) );
}

