/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(72) );
    set_long( get_long_by_id(72) );


    set_exits(({
        AREA_PATH + "forest_21.c", "northwest",
        AREA_PATH + "forest_22.c", "north",
        AREA_PATH + "forest_23.c", "northeast",
        AREA_PATH + "forest_71.c", "west",
        AREA_PATH + "forest_73.c", "east",
        AREA_PATH + "forest_121.c", "southwest",
        AREA_PATH + "forest_122.c", "south",
        AREA_PATH + "forest_123.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 72 ) );
}

