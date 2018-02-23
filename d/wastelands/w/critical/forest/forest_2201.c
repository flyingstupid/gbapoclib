/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2201) );
    set_long( get_long_by_id(2201) );


    set_exits(({
        AREA_PATH + "forest_2150.c", "northwest",
        AREA_PATH + "forest_2151.c", "north",
        AREA_PATH + "forest_2152.c", "northeast",
        AREA_PATH + "forest_2200.c", "west",
        AREA_PATH + "forest_2202.c", "east",
        AREA_PATH + "forest_2250.c", "southwest",
        AREA_PATH + "forest_2251.c", "south",
        AREA_PATH + "forest_2252.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2201 ) );
}

