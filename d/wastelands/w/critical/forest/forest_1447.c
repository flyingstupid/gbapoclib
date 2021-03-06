/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1447) );
    set_long( get_long_by_id(1447) );


    set_exits(({
        AREA_PATH + "forest_1396.c", "northwest",
        AREA_PATH + "forest_1397.c", "north",
        AREA_PATH + "forest_1398.c", "northeast",
        AREA_PATH + "forest_1446.c", "west",
        AREA_PATH + "forest_1448.c", "east",
        AREA_PATH + "forest_1496.c", "southwest",
        AREA_PATH + "forest_1497.c", "south",
        AREA_PATH + "forest_1498.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1447 ) );
}

