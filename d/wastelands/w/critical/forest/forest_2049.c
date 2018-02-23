/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2049) );
    set_long( get_long_by_id(2049) );


    set_exits(({
        AREA_PATH + "forest_1998.c", "northwest",
        AREA_PATH + "forest_1999.c", "north",
        AREA_PATH + "forest_2048.c", "west",
        AREA_PATH + "forest_2098.c", "southwest",
        AREA_PATH + "forest_2099.c", "south",
    }));

    set_room_type( get_room_scav_type( "forest", 2049 ) );
}

