/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(353) );
    set_long( get_long_by_id(353) );


    set_exits(({
        AREA_PATH + "forest_302.c", "northwest",
        AREA_PATH + "forest_303.c", "north",
        AREA_PATH + "forest_304.c", "northeast",
        AREA_PATH + "forest_352.c", "west",
        AREA_PATH + "forest_354.c", "east",
        AREA_PATH + "forest_402.c", "southwest",
        AREA_PATH + "forest_403.c", "south",
        AREA_PATH + "forest_404.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 353 ) );
}

