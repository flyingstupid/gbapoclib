/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1836) );
    set_long( get_long_by_id(1836) );


    set_exits(({
        AREA_PATH + "forest_1785.c", "northwest",
        AREA_PATH + "forest_1786.c", "north",
        AREA_PATH + "forest_1787.c", "northeast",
        AREA_PATH + "forest_1835.c", "west",
        AREA_PATH + "forest_1837.c", "east",
        AREA_PATH + "forest_1885.c", "southwest",
        AREA_PATH + "forest_1886.c", "south",
        AREA_PATH + "forest_1887.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1836 ) );
}

