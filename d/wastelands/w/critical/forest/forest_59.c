/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(59) );
    set_long( get_long_by_id(59) );


    set_exits(({
        AREA_PATH + "forest_8.c", "northwest",
        AREA_PATH + "forest_9.c", "north",
        AREA_PATH + "forest_10.c", "northeast",
        AREA_PATH + "forest_58.c", "west",
        AREA_PATH + "forest_60.c", "east",
        AREA_PATH + "forest_108.c", "southwest",
        AREA_PATH + "forest_109.c", "south",
        AREA_PATH + "forest_110.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 59 ) );
}

