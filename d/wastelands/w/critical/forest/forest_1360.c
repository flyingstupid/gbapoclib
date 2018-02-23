/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1360) );
    set_long( get_long_by_id(1360) );


    set_exits(({
        AREA_PATH + "forest_1309.c", "northwest",
        AREA_PATH + "forest_1310.c", "north",
        AREA_PATH + "forest_1311.c", "northeast",
        AREA_PATH + "forest_1359.c", "west",
        AREA_PATH + "forest_1361.c", "east",
        AREA_PATH + "forest_1409.c", "southwest",
        AREA_PATH + "forest_1410.c", "south",
        AREA_PATH + "forest_1411.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1360 ) );
}

