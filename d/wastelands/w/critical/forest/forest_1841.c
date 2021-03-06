/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1841) );
    set_long( get_long_by_id(1841) );


    set_exits(({
        AREA_PATH + "forest_1790.c", "northwest",
        AREA_PATH + "forest_1791.c", "north",
        AREA_PATH + "forest_1792.c", "northeast",
        AREA_PATH + "forest_1840.c", "west",
        AREA_PATH + "forest_1842.c", "east",
        AREA_PATH + "forest_1890.c", "southwest",
        AREA_PATH + "forest_1891.c", "south",
        AREA_PATH + "forest_1892.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1841 ) );
}

