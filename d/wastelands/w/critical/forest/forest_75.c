/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(75) );
    set_long( get_long_by_id(75) );


    set_exits(({
        AREA_PATH + "forest_24.c", "northwest",
        AREA_PATH + "forest_25.c", "north",
        AREA_PATH + "forest_26.c", "northeast",
        AREA_PATH + "forest_74.c", "west",
        AREA_PATH + "forest_76.c", "east",
        AREA_PATH + "forest_124.c", "southwest",
        AREA_PATH + "forest_125.c", "south",
        AREA_PATH + "forest_126.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 75 ) );
}

