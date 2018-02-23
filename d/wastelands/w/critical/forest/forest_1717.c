/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1717) );
    set_long( get_long_by_id(1717) );


    set_exits(({
        AREA_PATH + "forest_1666.c", "northwest",
        AREA_PATH + "forest_1667.c", "north",
        AREA_PATH + "forest_1668.c", "northeast",
        AREA_PATH + "forest_1716.c", "west",
        AREA_PATH + "forest_1718.c", "east",
        AREA_PATH + "forest_1766.c", "southwest",
        AREA_PATH + "forest_1767.c", "south",
        AREA_PATH + "forest_1768.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1717 ) );
}

