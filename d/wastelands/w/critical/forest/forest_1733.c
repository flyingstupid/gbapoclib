/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1733) );
    set_long( get_long_by_id(1733) );


    set_exits(({
        AREA_PATH + "forest_1682.c", "northwest",
        AREA_PATH + "forest_1683.c", "north",
        AREA_PATH + "forest_1684.c", "northeast",
        AREA_PATH + "forest_1732.c", "west",
        AREA_PATH + "forest_1734.c", "east",
        AREA_PATH + "forest_1782.c", "southwest",
        AREA_PATH + "forest_1783.c", "south",
        AREA_PATH + "forest_1784.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1733 ) );
}

