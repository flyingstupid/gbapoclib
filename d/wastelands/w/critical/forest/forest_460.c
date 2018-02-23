/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(460) );
    set_long( get_long_by_id(460) );


    set_exits(({
        AREA_PATH + "forest_409.c", "northwest",
        AREA_PATH + "forest_410.c", "north",
        AREA_PATH + "forest_411.c", "northeast",
        AREA_PATH + "forest_459.c", "west",
        AREA_PATH + "forest_461.c", "east",
        AREA_PATH + "forest_509.c", "southwest",
        AREA_PATH + "forest_510.c", "south",
        AREA_PATH + "forest_511.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 460 ) );
}

