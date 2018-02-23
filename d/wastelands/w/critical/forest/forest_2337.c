/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2337) );
    set_long( get_long_by_id(2337) );


    set_exits(({
        AREA_PATH + "forest_2286.c", "northwest",
        AREA_PATH + "forest_2287.c", "north",
        AREA_PATH + "forest_2288.c", "northeast",
        AREA_PATH + "forest_2336.c", "west",
        AREA_PATH + "forest_2338.c", "east",
        AREA_PATH + "forest_2386.c", "southwest",
        AREA_PATH + "forest_2387.c", "south",
        AREA_PATH + "forest_2388.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2337 ) );
}

