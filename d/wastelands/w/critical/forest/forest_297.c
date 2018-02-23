/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(297) );
    set_long( get_long_by_id(297) );


    set_exits(({
        AREA_PATH + "forest_246.c", "northwest",
        AREA_PATH + "forest_247.c", "north",
        AREA_PATH + "forest_248.c", "northeast",
        AREA_PATH + "forest_296.c", "west",
        AREA_PATH + "forest_298.c", "east",
        AREA_PATH + "forest_346.c", "southwest",
        AREA_PATH + "forest_347.c", "south",
        AREA_PATH + "forest_348.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 297 ) );
}

