/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2013) );
    set_long( get_long_by_id(2013) );


    set_exits(({
        AREA_PATH + "forest_1962.c", "northwest",
        AREA_PATH + "forest_1963.c", "north",
        AREA_PATH + "forest_1964.c", "northeast",
        AREA_PATH + "forest_2012.c", "west",
        AREA_PATH + "forest_2014.c", "east",
        AREA_PATH + "forest_2062.c", "southwest",
        AREA_PATH + "forest_2063.c", "south",
        AREA_PATH + "forest_2064.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2013 ) );
}

