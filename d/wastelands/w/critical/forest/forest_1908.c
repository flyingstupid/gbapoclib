/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1908) );
    set_long( get_long_by_id(1908) );


    set_exits(({
        AREA_PATH + "forest_1857.c", "northwest",
        AREA_PATH + "forest_1858.c", "north",
        AREA_PATH + "forest_1859.c", "northeast",
        AREA_PATH + "forest_1907.c", "west",
        AREA_PATH + "forest_1909.c", "east",
        AREA_PATH + "forest_1957.c", "southwest",
        AREA_PATH + "forest_1958.c", "south",
        AREA_PATH + "forest_1959.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1908 ) );
}

