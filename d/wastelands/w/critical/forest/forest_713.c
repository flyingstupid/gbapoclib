/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(713) );
    set_long( get_long_by_id(713) );


    set_exits(({
        AREA_PATH + "forest_662.c", "northwest",
        AREA_PATH + "forest_663.c", "north",
        AREA_PATH + "forest_664.c", "northeast",
        AREA_PATH + "forest_712.c", "west",
        AREA_PATH + "forest_714.c", "east",
        AREA_PATH + "forest_762.c", "southwest",
        AREA_PATH + "forest_763.c", "south",
        AREA_PATH + "forest_764.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 713 ) );
}

