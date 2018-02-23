/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2005) );
    set_long( get_long_by_id(2005) );


    set_exits(({
        AREA_PATH + "forest_1954.c", "northwest",
        AREA_PATH + "forest_1955.c", "north",
        AREA_PATH + "forest_1956.c", "northeast",
        AREA_PATH + "forest_2004.c", "west",
        AREA_PATH + "forest_2006.c", "east",
        AREA_PATH + "forest_2054.c", "southwest",
        AREA_PATH + "forest_2055.c", "south",
        AREA_PATH + "forest_2056.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2005 ) );
}

