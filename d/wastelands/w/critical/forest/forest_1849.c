/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1849) );
    set_long( get_long_by_id(1849) );


    set_exits(({
        AREA_PATH + "forest_1798.c", "northwest",
        AREA_PATH + "forest_1799.c", "north",
        AREA_PATH + "forest_1848.c", "west",
        AREA_PATH + "forest_1898.c", "southwest",
        AREA_PATH + "forest_1899.c", "south",
    }));

    set_room_type( get_room_scav_type( "forest", 1849 ) );
}

