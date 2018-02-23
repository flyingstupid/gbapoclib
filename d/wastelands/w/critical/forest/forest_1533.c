/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1533) );
    set_long( get_long_by_id(1533) );


    set_exits(({
        AREA_PATH + "forest_1482.c", "northwest",
        AREA_PATH + "forest_1483.c", "north",
        AREA_PATH + "forest_1484.c", "northeast",
        AREA_PATH + "forest_1532.c", "west",
        AREA_PATH + "forest_1534.c", "east",
        AREA_PATH + "forest_1582.c", "southwest",
        AREA_PATH + "forest_1583.c", "south",
        AREA_PATH + "forest_1584.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1533 ) );
}

