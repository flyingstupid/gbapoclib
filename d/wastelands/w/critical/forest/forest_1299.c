/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1299) );
    set_long( get_long_by_id(1299) );


    set_exits(({
        AREA_PATH + "forest_1248.c", "northwest",
        AREA_PATH + "forest_1249.c", "north",
        AREA_PATH + "forest_1298.c", "west",
        AREA_PATH + "forest_1348.c", "southwest",
        AREA_PATH + "forest_1349.c", "south",
    }));

    set_room_type( get_room_scav_type( "forest", 1299 ) );
}

