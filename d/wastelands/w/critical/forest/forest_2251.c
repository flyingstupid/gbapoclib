/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2251) );
    set_long( get_long_by_id(2251) );


    set_exits(({
        AREA_PATH + "forest_2200.c", "northwest",
        AREA_PATH + "forest_2201.c", "north",
        AREA_PATH + "forest_2202.c", "northeast",
        AREA_PATH + "forest_2250.c", "west",
        AREA_PATH + "forest_2252.c", "east",
        AREA_PATH + "forest_2300.c", "southwest",
        AREA_PATH + "forest_2301.c", "south",
        AREA_PATH + "forest_2302.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2251 ) );
}

