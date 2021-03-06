/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1853) );
    set_long( get_long_by_id(1853) );


    set_exits(({
        AREA_PATH + "forest_1802.c", "northwest",
        AREA_PATH + "forest_1803.c", "north",
        AREA_PATH + "forest_1804.c", "northeast",
        AREA_PATH + "forest_1852.c", "west",
        AREA_PATH + "forest_1854.c", "east",
        AREA_PATH + "forest_1902.c", "southwest",
        AREA_PATH + "forest_1903.c", "south",
        AREA_PATH + "forest_1904.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1853 ) );
}

