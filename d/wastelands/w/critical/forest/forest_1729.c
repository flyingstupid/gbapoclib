/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1729) );
    set_long( get_long_by_id(1729) );


    set_exits(({
        AREA_PATH + "forest_1678.c", "northwest",
        AREA_PATH + "forest_1679.c", "north",
        AREA_PATH + "forest_1680.c", "northeast",
        AREA_PATH + "forest_1728.c", "west",
        AREA_PATH + "forest_1730.c", "east",
        AREA_PATH + "forest_1778.c", "southwest",
        AREA_PATH + "forest_1779.c", "south",
        AREA_PATH + "forest_1780.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1729 ) );
}

