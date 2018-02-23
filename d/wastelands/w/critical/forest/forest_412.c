/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(412) );
    set_long( get_long_by_id(412) );


    set_exits(({
        AREA_PATH + "forest_361.c", "northwest",
        AREA_PATH + "forest_362.c", "north",
        AREA_PATH + "forest_363.c", "northeast",
        AREA_PATH + "forest_411.c", "west",
        AREA_PATH + "forest_413.c", "east",
        AREA_PATH + "forest_461.c", "southwest",
        AREA_PATH + "forest_462.c", "south",
        AREA_PATH + "forest_463.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 412 ) );
}

