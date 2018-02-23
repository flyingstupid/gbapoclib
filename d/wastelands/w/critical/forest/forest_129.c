/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(129) );
    set_long( get_long_by_id(129) );


    set_exits(({
        AREA_PATH + "forest_78.c", "northwest",
        AREA_PATH + "forest_79.c", "north",
        AREA_PATH + "forest_80.c", "northeast",
        AREA_PATH + "forest_128.c", "west",
        AREA_PATH + "forest_130.c", "east",
        AREA_PATH + "forest_178.c", "southwest",
        AREA_PATH + "forest_179.c", "south",
        AREA_PATH + "forest_180.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 129 ) );
}

