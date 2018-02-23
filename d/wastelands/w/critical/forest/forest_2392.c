/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2392) );
    set_long( get_long_by_id(2392) );


    set_exits(({
        AREA_PATH + "forest_2341.c", "northwest",
        AREA_PATH + "forest_2342.c", "north",
        AREA_PATH + "forest_2343.c", "northeast",
        AREA_PATH + "forest_2391.c", "west",
        AREA_PATH + "forest_2393.c", "east",
        AREA_PATH + "forest_2441.c", "southwest",
        AREA_PATH + "forest_2442.c", "south",
        AREA_PATH + "forest_2443.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2392 ) );
}

