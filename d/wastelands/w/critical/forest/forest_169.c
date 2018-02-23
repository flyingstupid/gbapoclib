/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(169) );
    set_long( get_long_by_id(169) );


    set_exits(({
        AREA_PATH + "forest_118.c", "northwest",
        AREA_PATH + "forest_119.c", "north",
        AREA_PATH + "forest_120.c", "northeast",
        AREA_PATH + "forest_168.c", "west",
        AREA_PATH + "forest_170.c", "east",
        AREA_PATH + "forest_218.c", "southwest",
        AREA_PATH + "forest_219.c", "south",
        AREA_PATH + "forest_220.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 169 ) );
}

