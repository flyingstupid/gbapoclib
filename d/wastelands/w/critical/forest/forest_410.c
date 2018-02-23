/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(410) );
    set_long( get_long_by_id(410) );


    set_exits(({
        AREA_PATH + "forest_359.c", "northwest",
        AREA_PATH + "forest_360.c", "north",
        AREA_PATH + "forest_361.c", "northeast",
        AREA_PATH + "forest_409.c", "west",
        AREA_PATH + "forest_411.c", "east",
        AREA_PATH + "forest_459.c", "southwest",
        AREA_PATH + "forest_460.c", "south",
        AREA_PATH + "forest_461.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 410 ) );
}

