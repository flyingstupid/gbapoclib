/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1718) );
    set_long( get_long_by_id(1718) );


    set_exits(({
        AREA_PATH + "forest_1667.c", "northwest",
        AREA_PATH + "forest_1668.c", "north",
        AREA_PATH + "forest_1669.c", "northeast",
        AREA_PATH + "forest_1717.c", "west",
        AREA_PATH + "forest_1719.c", "east",
        AREA_PATH + "forest_1767.c", "southwest",
        AREA_PATH + "forest_1768.c", "south",
        AREA_PATH + "forest_1769.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1718 ) );
}

