/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1852) );
    set_long( get_long_by_id(1852) );


    set_exits(({
        AREA_PATH + "forest_1801.c", "northwest",
        AREA_PATH + "forest_1802.c", "north",
        AREA_PATH + "forest_1803.c", "northeast",
        AREA_PATH + "forest_1851.c", "west",
        AREA_PATH + "forest_1853.c", "east",
        AREA_PATH + "forest_1901.c", "southwest",
        AREA_PATH + "forest_1902.c", "south",
        AREA_PATH + "forest_1903.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1852 ) );
}

