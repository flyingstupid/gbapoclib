/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1475) );
    set_long( get_long_by_id(1475) );


    set_exits(({
        AREA_PATH + "forest_1424.c", "northwest",
        AREA_PATH + "forest_1425.c", "north",
        AREA_PATH + "forest_1426.c", "northeast",
        AREA_PATH + "forest_1474.c", "west",
        AREA_PATH + "forest_1476.c", "east",
        AREA_PATH + "forest_1524.c", "southwest",
        AREA_PATH + "forest_1525.c", "south",
        AREA_PATH + "forest_1526.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1475 ) );
}

