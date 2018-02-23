/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2376) );
    set_long( get_long_by_id(2376) );


    set_exits(({
        AREA_PATH + "forest_2325.c", "northwest",
        AREA_PATH + "forest_2326.c", "north",
        AREA_PATH + "forest_2327.c", "northeast",
        AREA_PATH + "forest_2375.c", "west",
        AREA_PATH + "forest_2377.c", "east",
        AREA_PATH + "forest_2425.c", "southwest",
        AREA_PATH + "forest_2426.c", "south",
        AREA_PATH + "forest_2427.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2376 ) );
}

