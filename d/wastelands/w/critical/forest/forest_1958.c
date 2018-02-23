/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1958) );
    set_long( get_long_by_id(1958) );


    set_exits(({
        AREA_PATH + "forest_1907.c", "northwest",
        AREA_PATH + "forest_1908.c", "north",
        AREA_PATH + "forest_1909.c", "northeast",
        AREA_PATH + "forest_1957.c", "west",
        AREA_PATH + "forest_1959.c", "east",
        AREA_PATH + "forest_2007.c", "southwest",
        AREA_PATH + "forest_2008.c", "south",
        AREA_PATH + "forest_2009.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1958 ) );
}

