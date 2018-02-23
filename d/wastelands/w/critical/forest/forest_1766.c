/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1766) );
    set_long( get_long_by_id(1766) );


    set_exits(({
        AREA_PATH + "forest_1715.c", "northwest",
        AREA_PATH + "forest_1716.c", "north",
        AREA_PATH + "forest_1717.c", "northeast",
        AREA_PATH + "forest_1765.c", "west",
        AREA_PATH + "forest_1767.c", "east",
        AREA_PATH + "forest_1815.c", "southwest",
        AREA_PATH + "forest_1816.c", "south",
        AREA_PATH + "forest_1817.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1766 ) );
}

