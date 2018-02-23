/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(440) );
    set_long( get_long_by_id(440) );


    set_exits(({
        AREA_PATH + "forest_389.c", "northwest",
        AREA_PATH + "forest_390.c", "north",
        AREA_PATH + "forest_391.c", "northeast",
        AREA_PATH + "forest_439.c", "west",
        AREA_PATH + "forest_441.c", "east",
        AREA_PATH + "forest_489.c", "southwest",
        AREA_PATH + "forest_490.c", "south",
        AREA_PATH + "forest_491.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 440 ) );
}

