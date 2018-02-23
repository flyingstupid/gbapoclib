/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1337) );
    set_long( get_long_by_id(1337) );


    set_exits(({
        AREA_PATH + "forest_1286.c", "northwest",
        AREA_PATH + "forest_1287.c", "north",
        AREA_PATH + "forest_1288.c", "northeast",
        AREA_PATH + "forest_1336.c", "west",
        AREA_PATH + "forest_1338.c", "east",
        AREA_PATH + "forest_1386.c", "southwest",
        AREA_PATH + "forest_1387.c", "south",
        AREA_PATH + "forest_1388.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1337 ) );
}

