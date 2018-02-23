/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2042) );
    set_long( get_long_by_id(2042) );


    set_exits(({
        AREA_PATH + "forest_1991.c", "northwest",
        AREA_PATH + "forest_1992.c", "north",
        AREA_PATH + "forest_1993.c", "northeast",
        AREA_PATH + "forest_2041.c", "west",
        AREA_PATH + "forest_2043.c", "east",
        AREA_PATH + "forest_2091.c", "southwest",
        AREA_PATH + "forest_2092.c", "south",
        AREA_PATH + "forest_2093.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2042 ) );
}

