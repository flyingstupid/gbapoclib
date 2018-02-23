/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2078) );
    set_long( get_long_by_id(2078) );


    set_exits(({
        AREA_PATH + "forest_2027.c", "northwest",
        AREA_PATH + "forest_2028.c", "north",
        AREA_PATH + "forest_2029.c", "northeast",
        AREA_PATH + "forest_2077.c", "west",
        AREA_PATH + "forest_2079.c", "east",
        AREA_PATH + "forest_2127.c", "southwest",
        AREA_PATH + "forest_2128.c", "south",
        AREA_PATH + "forest_2129.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2078 ) );
}

