/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(746) );
    set_long( get_long_by_id(746) );


    set_exits(({
        AREA_PATH + "forest_695.c", "northwest",
        AREA_PATH + "forest_696.c", "north",
        AREA_PATH + "forest_697.c", "northeast",
        AREA_PATH + "forest_745.c", "west",
        AREA_PATH + "forest_747.c", "east",
        AREA_PATH + "forest_795.c", "southwest",
        AREA_PATH + "forest_796.c", "south",
        AREA_PATH + "forest_797.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 746 ) );
}

