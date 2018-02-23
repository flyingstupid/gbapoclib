/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(491) );
    set_long( get_long_by_id(491) );


    set_exits(({
        AREA_PATH + "forest_440.c", "northwest",
        AREA_PATH + "forest_441.c", "north",
        AREA_PATH + "forest_442.c", "northeast",
        AREA_PATH + "forest_490.c", "west",
        AREA_PATH + "forest_492.c", "east",
        AREA_PATH + "forest_540.c", "southwest",
        AREA_PATH + "forest_541.c", "south",
        AREA_PATH + "forest_542.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 491 ) );
}

