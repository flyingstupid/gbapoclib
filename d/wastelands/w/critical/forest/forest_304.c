/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(304) );
    set_long( get_long_by_id(304) );


    set_exits(({
        AREA_PATH + "forest_253.c", "northwest",
        AREA_PATH + "forest_254.c", "north",
        AREA_PATH + "forest_255.c", "northeast",
        AREA_PATH + "forest_303.c", "west",
        AREA_PATH + "forest_305.c", "east",
        AREA_PATH + "forest_353.c", "southwest",
        AREA_PATH + "forest_354.c", "south",
        AREA_PATH + "forest_355.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 304 ) );
}

