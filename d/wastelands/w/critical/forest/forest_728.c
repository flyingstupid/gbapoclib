/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(728) );
    set_long( get_long_by_id(728) );


    set_exits(({
        AREA_PATH + "forest_677.c", "northwest",
        AREA_PATH + "forest_678.c", "north",
        AREA_PATH + "forest_679.c", "northeast",
        AREA_PATH + "forest_727.c", "west",
        AREA_PATH + "forest_729.c", "east",
        AREA_PATH + "forest_777.c", "southwest",
        AREA_PATH + "forest_778.c", "south",
        AREA_PATH + "forest_779.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 728 ) );
}

