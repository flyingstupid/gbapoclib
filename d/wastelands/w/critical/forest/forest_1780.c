/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1780) );
    set_long( get_long_by_id(1780) );


    set_exits(({
        AREA_PATH + "forest_1729.c", "northwest",
        AREA_PATH + "forest_1730.c", "north",
        AREA_PATH + "forest_1731.c", "northeast",
        AREA_PATH + "forest_1779.c", "west",
        AREA_PATH + "forest_1781.c", "east",
        AREA_PATH + "forest_1829.c", "southwest",
        AREA_PATH + "forest_1830.c", "south",
        AREA_PATH + "forest_1831.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1780 ) );
}

