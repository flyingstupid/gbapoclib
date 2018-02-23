/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1524) );
    set_long( get_long_by_id(1524) );


    set_exits(({
        AREA_PATH + "forest_1473.c", "northwest",
        AREA_PATH + "forest_1474.c", "north",
        AREA_PATH + "forest_1475.c", "northeast",
        AREA_PATH + "forest_1523.c", "west",
        AREA_PATH + "forest_1525.c", "east",
        AREA_PATH + "forest_1573.c", "southwest",
        AREA_PATH + "forest_1574.c", "south",
        AREA_PATH + "forest_1575.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1524 ) );
}

