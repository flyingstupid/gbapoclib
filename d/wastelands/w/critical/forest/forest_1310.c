/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1310) );
    set_long( get_long_by_id(1310) );


    set_exits(({
        AREA_PATH + "forest_1259.c", "northwest",
        AREA_PATH + "forest_1260.c", "north",
        AREA_PATH + "forest_1261.c", "northeast",
        AREA_PATH + "forest_1309.c", "west",
        AREA_PATH + "forest_1311.c", "east",
        AREA_PATH + "forest_1359.c", "southwest",
        AREA_PATH + "forest_1360.c", "south",
        AREA_PATH + "forest_1361.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1310 ) );
}

