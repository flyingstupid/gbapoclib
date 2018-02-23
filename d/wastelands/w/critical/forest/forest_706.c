/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(706) );
    set_long( get_long_by_id(706) );


    set_exits(({
        AREA_PATH + "forest_655.c", "northwest",
        AREA_PATH + "forest_656.c", "north",
        AREA_PATH + "forest_657.c", "northeast",
        AREA_PATH + "forest_705.c", "west",
        AREA_PATH + "forest_707.c", "east",
        AREA_PATH + "forest_755.c", "southwest",
        AREA_PATH + "forest_756.c", "south",
        AREA_PATH + "forest_757.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 706 ) );
}

