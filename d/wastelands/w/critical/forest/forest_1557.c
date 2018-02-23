/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1557) );
    set_long( get_long_by_id(1557) );


    set_exits(({
        AREA_PATH + "forest_1506.c", "northwest",
        AREA_PATH + "forest_1507.c", "north",
        AREA_PATH + "forest_1508.c", "northeast",
        AREA_PATH + "forest_1556.c", "west",
        AREA_PATH + "forest_1558.c", "east",
        AREA_PATH + "forest_1606.c", "southwest",
        AREA_PATH + "forest_1607.c", "south",
        AREA_PATH + "forest_1608.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1557 ) );
}

