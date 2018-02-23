/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1778) );
    set_long( get_long_by_id(1778) );


    set_exits(({
        AREA_PATH + "forest_1727.c", "northwest",
        AREA_PATH + "forest_1728.c", "north",
        AREA_PATH + "forest_1729.c", "northeast",
        AREA_PATH + "forest_1777.c", "west",
        AREA_PATH + "forest_1779.c", "east",
        AREA_PATH + "forest_1827.c", "southwest",
        AREA_PATH + "forest_1828.c", "south",
        AREA_PATH + "forest_1829.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1778 ) );
}

