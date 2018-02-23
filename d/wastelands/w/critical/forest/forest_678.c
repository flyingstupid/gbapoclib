/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(678) );
    set_long( get_long_by_id(678) );


    set_exits(({
        AREA_PATH + "forest_627.c", "northwest",
        AREA_PATH + "forest_628.c", "north",
        AREA_PATH + "forest_629.c", "northeast",
        AREA_PATH + "forest_677.c", "west",
        AREA_PATH + "forest_679.c", "east",
        AREA_PATH + "forest_727.c", "southwest",
        AREA_PATH + "forest_728.c", "south",
        AREA_PATH + "forest_729.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 678 ) );
}

