/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1786) );
    set_long( get_long_by_id(1786) );


    set_exits(({
        AREA_PATH + "forest_1735.c", "northwest",
        AREA_PATH + "forest_1736.c", "north",
        AREA_PATH + "forest_1737.c", "northeast",
        AREA_PATH + "forest_1785.c", "west",
        AREA_PATH + "forest_1787.c", "east",
        AREA_PATH + "forest_1835.c", "southwest",
        AREA_PATH + "forest_1836.c", "south",
        AREA_PATH + "forest_1837.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1786 ) );
}

