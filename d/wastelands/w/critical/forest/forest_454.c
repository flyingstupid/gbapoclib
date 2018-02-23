/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(454) );
    set_long( get_long_by_id(454) );


    set_exits(({
        AREA_PATH + "forest_403.c", "northwest",
        AREA_PATH + "forest_404.c", "north",
        AREA_PATH + "forest_405.c", "northeast",
        AREA_PATH + "forest_453.c", "west",
        AREA_PATH + "forest_455.c", "east",
        AREA_PATH + "forest_503.c", "southwest",
        AREA_PATH + "forest_504.c", "south",
        AREA_PATH + "forest_505.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 454 ) );
}

