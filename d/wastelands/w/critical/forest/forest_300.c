/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(300) );
    set_long( get_long_by_id(300) );


    set_exits(({
        AREA_PATH + "forest_250.c", "north",
        AREA_PATH + "forest_251.c", "northeast",
        AREA_PATH + "forest_301.c", "east",
        AREA_PATH + "forest_350.c", "south",
        AREA_PATH + "forest_351.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 300 ) );
}

