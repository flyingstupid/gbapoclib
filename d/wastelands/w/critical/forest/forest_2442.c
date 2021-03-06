/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2442) );
    set_long( get_long_by_id(2442) );


    set_exits(({
        AREA_PATH + "forest_2391.c", "northwest",
        AREA_PATH + "forest_2392.c", "north",
        AREA_PATH + "forest_2393.c", "northeast",
        AREA_PATH + "forest_2441.c", "west",
        AREA_PATH + "forest_2443.c", "east",
        AREA_PATH + "forest_2491.c", "southwest",
        AREA_PATH + "forest_2492.c", "south",
        AREA_PATH + "forest_2493.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2442 ) );
}

