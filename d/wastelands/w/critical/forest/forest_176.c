/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(176) );
    set_long( get_long_by_id(176) );


    set_exits(({
        AREA_PATH + "forest_125.c", "northwest",
        AREA_PATH + "forest_126.c", "north",
        AREA_PATH + "forest_127.c", "northeast",
        AREA_PATH + "forest_175.c", "west",
        AREA_PATH + "forest_177.c", "east",
        AREA_PATH + "forest_225.c", "southwest",
        AREA_PATH + "forest_226.c", "south",
        AREA_PATH + "forest_227.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 176 ) );
}

