/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1554) );
    set_long( get_long_by_id(1554) );


    set_exits(({
        AREA_PATH + "forest_1503.c", "northwest",
        AREA_PATH + "forest_1504.c", "north",
        AREA_PATH + "forest_1505.c", "northeast",
        AREA_PATH + "forest_1553.c", "west",
        AREA_PATH + "forest_1555.c", "east",
        AREA_PATH + "forest_1603.c", "southwest",
        AREA_PATH + "forest_1604.c", "south",
        AREA_PATH + "forest_1605.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1554 ) );
}

