/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1558) );
    set_long( get_long_by_id(1558) );


    set_exits(({
        AREA_PATH + "forest_1507.c", "northwest",
        AREA_PATH + "forest_1508.c", "north",
        AREA_PATH + "forest_1509.c", "northeast",
        AREA_PATH + "forest_1557.c", "west",
        AREA_PATH + "forest_1559.c", "east",
        AREA_PATH + "forest_1607.c", "southwest",
        AREA_PATH + "forest_1608.c", "south",
        AREA_PATH + "forest_1609.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1558 ) );
}

