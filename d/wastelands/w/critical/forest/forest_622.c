/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(622) );
    set_long( get_long_by_id(622) );


    set_exits(({
        AREA_PATH + "forest_571.c", "northwest",
        AREA_PATH + "forest_572.c", "north",
        AREA_PATH + "forest_573.c", "northeast",
        AREA_PATH + "forest_621.c", "west",
        AREA_PATH + "forest_623.c", "east",
        AREA_PATH + "forest_671.c", "southwest",
        AREA_PATH + "forest_672.c", "south",
        AREA_PATH + "forest_673.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 622 ) );
}

