/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2211) );
    set_long( get_long_by_id(2211) );


    set_exits(({
        AREA_PATH + "forest_2160.c", "northwest",
        AREA_PATH + "forest_2161.c", "north",
        AREA_PATH + "forest_2162.c", "northeast",
        AREA_PATH + "forest_2210.c", "west",
        AREA_PATH + "forest_2212.c", "east",
        AREA_PATH + "forest_2260.c", "southwest",
        AREA_PATH + "forest_2261.c", "south",
        AREA_PATH + "forest_2262.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2211 ) );
}

