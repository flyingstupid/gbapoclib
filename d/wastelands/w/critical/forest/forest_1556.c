/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1556) );
    set_long( get_long_by_id(1556) );


    set_exits(({
        AREA_PATH + "forest_1505.c", "northwest",
        AREA_PATH + "forest_1506.c", "north",
        AREA_PATH + "forest_1507.c", "northeast",
        AREA_PATH + "forest_1555.c", "west",
        AREA_PATH + "forest_1557.c", "east",
        AREA_PATH + "forest_1605.c", "southwest",
        AREA_PATH + "forest_1606.c", "south",
        AREA_PATH + "forest_1607.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1556 ) );
}

