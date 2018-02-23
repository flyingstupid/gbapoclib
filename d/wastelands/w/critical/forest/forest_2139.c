/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2139) );
    set_long( get_long_by_id(2139) );


    set_exits(({
        AREA_PATH + "forest_2088.c", "northwest",
        AREA_PATH + "forest_2089.c", "north",
        AREA_PATH + "forest_2090.c", "northeast",
        AREA_PATH + "forest_2138.c", "west",
        AREA_PATH + "forest_2140.c", "east",
        AREA_PATH + "forest_2188.c", "southwest",
        AREA_PATH + "forest_2189.c", "south",
        AREA_PATH + "forest_2190.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2139 ) );
}

