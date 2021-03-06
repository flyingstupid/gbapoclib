/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1453) );
    set_long( get_long_by_id(1453) );


    set_exits(({
        AREA_PATH + "forest_1402.c", "northwest",
        AREA_PATH + "forest_1403.c", "north",
        AREA_PATH + "forest_1404.c", "northeast",
        AREA_PATH + "forest_1452.c", "west",
        AREA_PATH + "forest_1454.c", "east",
        AREA_PATH + "forest_1502.c", "southwest",
        AREA_PATH + "forest_1503.c", "south",
        AREA_PATH + "forest_1504.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1453 ) );
}

