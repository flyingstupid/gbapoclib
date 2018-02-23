/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2060) );
    set_long( get_long_by_id(2060) );


    set_exits(({
        AREA_PATH + "forest_2009.c", "northwest",
        AREA_PATH + "forest_2010.c", "north",
        AREA_PATH + "forest_2011.c", "northeast",
        AREA_PATH + "forest_2059.c", "west",
        AREA_PATH + "forest_2061.c", "east",
        AREA_PATH + "forest_2109.c", "southwest",
        AREA_PATH + "forest_2110.c", "south",
        AREA_PATH + "forest_2111.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2060 ) );
}

