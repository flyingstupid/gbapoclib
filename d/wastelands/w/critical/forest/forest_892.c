/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(892) );
    set_long( get_long_by_id(892) );


    set_exits(({
        AREA_PATH + "forest_841.c", "northwest",
        AREA_PATH + "forest_842.c", "north",
        AREA_PATH + "forest_843.c", "northeast",
        AREA_PATH + "forest_891.c", "west",
        AREA_PATH + "forest_893.c", "east",
        AREA_PATH + "forest_941.c", "southwest",
        AREA_PATH + "forest_942.c", "south",
        AREA_PATH + "forest_943.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 892 ) );
}

