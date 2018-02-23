/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2006) );
    set_long( get_long_by_id(2006) );


    set_exits(({
        AREA_PATH + "forest_1955.c", "northwest",
        AREA_PATH + "forest_1956.c", "north",
        AREA_PATH + "forest_1957.c", "northeast",
        AREA_PATH + "forest_2005.c", "west",
        AREA_PATH + "forest_2007.c", "east",
        AREA_PATH + "forest_2055.c", "southwest",
        AREA_PATH + "forest_2056.c", "south",
        AREA_PATH + "forest_2057.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2006 ) );
}

