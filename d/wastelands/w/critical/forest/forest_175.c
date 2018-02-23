/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(175) );
    set_long( get_long_by_id(175) );


    set_exits(({
        AREA_PATH + "forest_124.c", "northwest",
        AREA_PATH + "forest_125.c", "north",
        AREA_PATH + "forest_126.c", "northeast",
        AREA_PATH + "forest_174.c", "west",
        AREA_PATH + "forest_176.c", "east",
        AREA_PATH + "forest_224.c", "southwest",
        AREA_PATH + "forest_225.c", "south",
        AREA_PATH + "forest_226.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 175 ) );
}

