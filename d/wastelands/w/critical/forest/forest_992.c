/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(992) );
    set_long( get_long_by_id(992) );


    set_exits(({
        AREA_PATH + "forest_941.c", "northwest",
        AREA_PATH + "forest_942.c", "north",
        AREA_PATH + "forest_943.c", "northeast",
        AREA_PATH + "forest_991.c", "west",
        AREA_PATH + "forest_993.c", "east",
        AREA_PATH + "forest_1041.c", "southwest",
        AREA_PATH + "forest_1042.c", "south",
        AREA_PATH + "forest_1043.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 992 ) );
}

