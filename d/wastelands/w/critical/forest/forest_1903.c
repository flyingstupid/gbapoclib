/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1903) );
    set_long( get_long_by_id(1903) );


    set_exits(({
        AREA_PATH + "forest_1852.c", "northwest",
        AREA_PATH + "forest_1853.c", "north",
        AREA_PATH + "forest_1854.c", "northeast",
        AREA_PATH + "forest_1902.c", "west",
        AREA_PATH + "forest_1904.c", "east",
        AREA_PATH + "forest_1952.c", "southwest",
        AREA_PATH + "forest_1953.c", "south",
        AREA_PATH + "forest_1954.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1903 ) );
}

