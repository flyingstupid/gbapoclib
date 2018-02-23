/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1408) );
    set_long( get_long_by_id(1408) );


    set_exits(({
        AREA_PATH + "forest_1357.c", "northwest",
        AREA_PATH + "forest_1358.c", "north",
        AREA_PATH + "forest_1359.c", "northeast",
        AREA_PATH + "forest_1407.c", "west",
        AREA_PATH + "forest_1409.c", "east",
        AREA_PATH + "forest_1457.c", "southwest",
        AREA_PATH + "forest_1458.c", "south",
        AREA_PATH + "forest_1459.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1408 ) );
}

