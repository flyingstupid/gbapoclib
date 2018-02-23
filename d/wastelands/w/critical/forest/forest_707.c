/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(707) );
    set_long( get_long_by_id(707) );


    set_exits(({
        AREA_PATH + "forest_656.c", "northwest",
        AREA_PATH + "forest_657.c", "north",
        AREA_PATH + "forest_658.c", "northeast",
        AREA_PATH + "forest_706.c", "west",
        AREA_PATH + "forest_708.c", "east",
        AREA_PATH + "forest_756.c", "southwest",
        AREA_PATH + "forest_757.c", "south",
        AREA_PATH + "forest_758.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 707 ) );
}

