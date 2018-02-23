/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2062) );
    set_long( get_long_by_id(2062) );


    set_exits(({
        AREA_PATH + "forest_2011.c", "northwest",
        AREA_PATH + "forest_2012.c", "north",
        AREA_PATH + "forest_2013.c", "northeast",
        AREA_PATH + "forest_2061.c", "west",
        AREA_PATH + "forest_2063.c", "east",
        AREA_PATH + "forest_2111.c", "southwest",
        AREA_PATH + "forest_2112.c", "south",
        AREA_PATH + "forest_2113.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2062 ) );
}

