/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(407) );
    set_long( get_long_by_id(407) );


    set_exits(({
        AREA_PATH + "forest_356.c", "northwest",
        AREA_PATH + "forest_357.c", "north",
        AREA_PATH + "forest_358.c", "northeast",
        AREA_PATH + "forest_406.c", "west",
        AREA_PATH + "forest_408.c", "east",
        AREA_PATH + "forest_456.c", "southwest",
        AREA_PATH + "forest_457.c", "south",
        AREA_PATH + "forest_458.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 407 ) );
}

