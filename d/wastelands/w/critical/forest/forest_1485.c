/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1485) );
    set_long( get_long_by_id(1485) );


    set_exits(({
        AREA_PATH + "forest_1434.c", "northwest",
        AREA_PATH + "forest_1435.c", "north",
        AREA_PATH + "forest_1436.c", "northeast",
        AREA_PATH + "forest_1484.c", "west",
        AREA_PATH + "forest_1486.c", "east",
        AREA_PATH + "forest_1534.c", "southwest",
        AREA_PATH + "forest_1535.c", "south",
        AREA_PATH + "forest_1536.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1485 ) );
}

