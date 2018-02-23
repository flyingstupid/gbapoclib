/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(827) );
    set_long( get_long_by_id(827) );


    set_exits(({
        AREA_PATH + "forest_776.c", "northwest",
        AREA_PATH + "forest_777.c", "north",
        AREA_PATH + "forest_778.c", "northeast",
        AREA_PATH + "forest_826.c", "west",
        AREA_PATH + "forest_828.c", "east",
        AREA_PATH + "forest_876.c", "southwest",
        AREA_PATH + "forest_877.c", "south",
        AREA_PATH + "forest_878.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 827 ) );
}

