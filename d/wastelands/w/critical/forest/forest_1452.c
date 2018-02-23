/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1452) );
    set_long( get_long_by_id(1452) );


    set_exits(({
        AREA_PATH + "forest_1401.c", "northwest",
        AREA_PATH + "forest_1402.c", "north",
        AREA_PATH + "forest_1403.c", "northeast",
        AREA_PATH + "forest_1451.c", "west",
        AREA_PATH + "forest_1453.c", "east",
        AREA_PATH + "forest_1501.c", "southwest",
        AREA_PATH + "forest_1502.c", "south",
        AREA_PATH + "forest_1503.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1452 ) );
}

