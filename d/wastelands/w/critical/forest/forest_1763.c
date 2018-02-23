/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1763) );
    set_long( get_long_by_id(1763) );


    set_exits(({
        AREA_PATH + "forest_1712.c", "northwest",
        AREA_PATH + "forest_1713.c", "north",
        AREA_PATH + "forest_1714.c", "northeast",
        AREA_PATH + "forest_1762.c", "west",
        AREA_PATH + "forest_1764.c", "east",
        AREA_PATH + "forest_1812.c", "southwest",
        AREA_PATH + "forest_1813.c", "south",
        AREA_PATH + "forest_1814.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1763 ) );
}

