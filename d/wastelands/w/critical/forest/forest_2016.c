/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2016) );
    set_long( get_long_by_id(2016) );


    set_exits(({
        AREA_PATH + "forest_1965.c", "northwest",
        AREA_PATH + "forest_1966.c", "north",
        AREA_PATH + "forest_1967.c", "northeast",
        AREA_PATH + "forest_2015.c", "west",
        AREA_PATH + "forest_2017.c", "east",
        AREA_PATH + "forest_2065.c", "southwest",
        AREA_PATH + "forest_2066.c", "south",
        AREA_PATH + "forest_2067.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2016 ) );
}

