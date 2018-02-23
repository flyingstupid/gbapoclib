/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1551) );
    set_long( get_long_by_id(1551) );


    set_exits(({
        AREA_PATH + "forest_1500.c", "northwest",
        AREA_PATH + "forest_1501.c", "north",
        AREA_PATH + "forest_1502.c", "northeast",
        AREA_PATH + "forest_1550.c", "west",
        AREA_PATH + "forest_1552.c", "east",
        AREA_PATH + "forest_1600.c", "southwest",
        AREA_PATH + "forest_1601.c", "south",
        AREA_PATH + "forest_1602.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1551 ) );
}

