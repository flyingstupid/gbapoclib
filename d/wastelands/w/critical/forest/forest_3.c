/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(3) );
    set_long( get_long_by_id(3) );


    set_exits(({
        AREA_PATH + "forest_2.c", "west",
        AREA_PATH + "forest_4.c", "east",
        AREA_PATH + "forest_52.c", "southwest",
        AREA_PATH + "forest_53.c", "south",
        AREA_PATH + "forest_54.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 3 ) );
}

