/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1312) );
    set_long( get_long_by_id(1312) );


    set_exits(({
        AREA_PATH + "forest_1261.c", "northwest",
        AREA_PATH + "forest_1262.c", "north",
        AREA_PATH + "forest_1263.c", "northeast",
        AREA_PATH + "forest_1311.c", "west",
        AREA_PATH + "forest_1313.c", "east",
        AREA_PATH + "forest_1361.c", "southwest",
        AREA_PATH + "forest_1362.c", "south",
        AREA_PATH + "forest_1363.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1312 ) );
}

