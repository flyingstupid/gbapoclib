/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2152) );
    set_long( get_long_by_id(2152) );


    set_exits(({
        AREA_PATH + "forest_2101.c", "northwest",
        AREA_PATH + "forest_2102.c", "north",
        AREA_PATH + "forest_2103.c", "northeast",
        AREA_PATH + "forest_2151.c", "west",
        AREA_PATH + "forest_2153.c", "east",
        AREA_PATH + "forest_2201.c", "southwest",
        AREA_PATH + "forest_2202.c", "south",
        AREA_PATH + "forest_2203.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2152 ) );
}

