/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(858) );
    set_long( get_long_by_id(858) );


    set_exits(({
        AREA_PATH + "forest_807.c", "northwest",
        AREA_PATH + "forest_808.c", "north",
        AREA_PATH + "forest_809.c", "northeast",
        AREA_PATH + "forest_857.c", "west",
        AREA_PATH + "forest_859.c", "east",
        AREA_PATH + "forest_907.c", "southwest",
        AREA_PATH + "forest_908.c", "south",
        AREA_PATH + "forest_909.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 858 ) );
}

