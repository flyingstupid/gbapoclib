/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1917) );
    set_long( get_long_by_id(1917) );


    set_exits(({
        AREA_PATH + "forest_1866.c", "northwest",
        AREA_PATH + "forest_1867.c", "north",
        AREA_PATH + "forest_1868.c", "northeast",
        AREA_PATH + "forest_1916.c", "west",
        AREA_PATH + "forest_1918.c", "east",
        AREA_PATH + "forest_1966.c", "southwest",
        AREA_PATH + "forest_1967.c", "south",
        AREA_PATH + "forest_1968.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1917 ) );
}

