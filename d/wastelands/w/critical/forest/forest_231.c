/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(231) );
    set_long( get_long_by_id(231) );


    set_exits(({
        AREA_PATH + "forest_180.c", "northwest",
        AREA_PATH + "forest_181.c", "north",
        AREA_PATH + "forest_182.c", "northeast",
        AREA_PATH + "forest_230.c", "west",
        AREA_PATH + "forest_232.c", "east",
        AREA_PATH + "forest_280.c", "southwest",
        AREA_PATH + "forest_281.c", "south",
        AREA_PATH + "forest_282.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 231 ) );
}

