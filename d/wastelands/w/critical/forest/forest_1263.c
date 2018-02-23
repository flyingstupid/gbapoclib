/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1263) );
    set_long( get_long_by_id(1263) );


    set_exits(({
        AREA_PATH + "forest_1212.c", "northwest",
        AREA_PATH + "forest_1213.c", "north",
        AREA_PATH + "forest_1214.c", "northeast",
        AREA_PATH + "forest_1262.c", "west",
        AREA_PATH + "forest_1264.c", "east",
        AREA_PATH + "forest_1312.c", "southwest",
        AREA_PATH + "forest_1313.c", "south",
        AREA_PATH + "forest_1314.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1263 ) );
}

