/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2066) );
    set_long( get_long_by_id(2066) );


    set_exits(({
        AREA_PATH + "forest_2015.c", "northwest",
        AREA_PATH + "forest_2016.c", "north",
        AREA_PATH + "forest_2017.c", "northeast",
        AREA_PATH + "forest_2065.c", "west",
        AREA_PATH + "forest_2067.c", "east",
        AREA_PATH + "forest_2115.c", "southwest",
        AREA_PATH + "forest_2116.c", "south",
        AREA_PATH + "forest_2117.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2066 ) );
}

