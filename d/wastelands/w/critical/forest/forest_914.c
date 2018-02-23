/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(914) );
    set_long( get_long_by_id(914) );


    set_exits(({
        AREA_PATH + "forest_863.c", "northwest",
        AREA_PATH + "forest_864.c", "north",
        AREA_PATH + "forest_865.c", "northeast",
        AREA_PATH + "forest_913.c", "west",
        AREA_PATH + "forest_915.c", "east",
        AREA_PATH + "forest_963.c", "southwest",
        AREA_PATH + "forest_964.c", "south",
        AREA_PATH + "forest_965.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 914 ) );
}

