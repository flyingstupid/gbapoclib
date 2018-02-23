/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1631) );
    set_long( get_long_by_id(1631) );


    set_exits(({
        AREA_PATH + "forest_1580.c", "northwest",
        AREA_PATH + "forest_1581.c", "north",
        AREA_PATH + "forest_1582.c", "northeast",
        AREA_PATH + "forest_1630.c", "west",
        AREA_PATH + "forest_1632.c", "east",
        AREA_PATH + "forest_1680.c", "southwest",
        AREA_PATH + "forest_1681.c", "south",
        AREA_PATH + "forest_1682.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1631 ) );
}

