/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(493) );
    set_long( get_long_by_id(493) );


    set_exits(({
        AREA_PATH + "forest_442.c", "northwest",
        AREA_PATH + "forest_443.c", "north",
        AREA_PATH + "forest_444.c", "northeast",
        AREA_PATH + "forest_492.c", "west",
        AREA_PATH + "forest_494.c", "east",
        AREA_PATH + "forest_542.c", "southwest",
        AREA_PATH + "forest_543.c", "south",
        AREA_PATH + "forest_544.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 493 ) );
}

