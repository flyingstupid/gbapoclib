/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1785) );
    set_long( get_long_by_id(1785) );


    set_exits(({
        AREA_PATH + "forest_1734.c", "northwest",
        AREA_PATH + "forest_1735.c", "north",
        AREA_PATH + "forest_1736.c", "northeast",
        AREA_PATH + "forest_1784.c", "west",
        AREA_PATH + "forest_1786.c", "east",
        AREA_PATH + "forest_1834.c", "southwest",
        AREA_PATH + "forest_1835.c", "south",
        AREA_PATH + "forest_1836.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1785 ) );
}

