/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(223) );
    set_long( get_long_by_id(223) );


    set_exits(({
        AREA_PATH + "forest_172.c", "northwest",
        AREA_PATH + "forest_173.c", "north",
        AREA_PATH + "forest_174.c", "northeast",
        AREA_PATH + "forest_222.c", "west",
        AREA_PATH + "forest_224.c", "east",
        AREA_PATH + "forest_272.c", "southwest",
        AREA_PATH + "forest_273.c", "south",
        AREA_PATH + "forest_274.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 223 ) );
}

