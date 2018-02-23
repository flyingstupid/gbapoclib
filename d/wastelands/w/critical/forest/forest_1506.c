/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1506) );
    set_long( get_long_by_id(1506) );


    set_exits(({
        AREA_PATH + "forest_1455.c", "northwest",
        AREA_PATH + "forest_1456.c", "north",
        AREA_PATH + "forest_1457.c", "northeast",
        AREA_PATH + "forest_1505.c", "west",
        AREA_PATH + "forest_1507.c", "east",
        AREA_PATH + "forest_1555.c", "southwest",
        AREA_PATH + "forest_1556.c", "south",
        AREA_PATH + "forest_1557.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1506 ) );
}

