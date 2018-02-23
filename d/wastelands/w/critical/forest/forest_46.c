/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(46) );
    set_long( get_long_by_id(46) );


    set_exits(({
        AREA_PATH + "forest_45.c", "west",
        AREA_PATH + "forest_47.c", "east",
        AREA_PATH + "forest_95.c", "southwest",
        AREA_PATH + "forest_96.c", "south",
        AREA_PATH + "forest_97.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 46 ) );
}

