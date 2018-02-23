/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(215) );
    set_long( get_long_by_id(215) );


    set_exits(({
        AREA_PATH + "forest_164.c", "northwest",
        AREA_PATH + "forest_165.c", "north",
        AREA_PATH + "forest_166.c", "northeast",
        AREA_PATH + "forest_214.c", "west",
        AREA_PATH + "forest_216.c", "east",
        AREA_PATH + "forest_264.c", "southwest",
        AREA_PATH + "forest_265.c", "south",
        AREA_PATH + "forest_266.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 215 ) );
}

