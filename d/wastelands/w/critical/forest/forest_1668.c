/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1668) );
    set_long( get_long_by_id(1668) );


    set_exits(({
        AREA_PATH + "forest_1617.c", "northwest",
        AREA_PATH + "forest_1618.c", "north",
        AREA_PATH + "forest_1619.c", "northeast",
        AREA_PATH + "forest_1667.c", "west",
        AREA_PATH + "forest_1669.c", "east",
        AREA_PATH + "forest_1717.c", "southwest",
        AREA_PATH + "forest_1718.c", "south",
        AREA_PATH + "forest_1719.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1668 ) );
}

