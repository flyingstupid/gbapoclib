/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2377) );
    set_long( get_long_by_id(2377) );


    set_exits(({
        AREA_PATH + "forest_2326.c", "northwest",
        AREA_PATH + "forest_2327.c", "north",
        AREA_PATH + "forest_2328.c", "northeast",
        AREA_PATH + "forest_2376.c", "west",
        AREA_PATH + "forest_2378.c", "east",
        AREA_PATH + "forest_2426.c", "southwest",
        AREA_PATH + "forest_2427.c", "south",
        AREA_PATH + "forest_2428.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2377 ) );
}
