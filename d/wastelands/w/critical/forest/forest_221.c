/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(221) );
    set_long( get_long_by_id(221) );


    set_exits(({
        AREA_PATH + "forest_170.c", "northwest",
        AREA_PATH + "forest_171.c", "north",
        AREA_PATH + "forest_172.c", "northeast",
        AREA_PATH + "forest_220.c", "west",
        AREA_PATH + "forest_222.c", "east",
        AREA_PATH + "forest_270.c", "southwest",
        AREA_PATH + "forest_271.c", "south",
        AREA_PATH + "forest_272.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 221 ) );
}

