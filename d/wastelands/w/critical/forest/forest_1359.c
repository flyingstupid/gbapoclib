/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1359) );
    set_long( get_long_by_id(1359) );


    set_exits(({
        AREA_PATH + "forest_1308.c", "northwest",
        AREA_PATH + "forest_1309.c", "north",
        AREA_PATH + "forest_1310.c", "northeast",
        AREA_PATH + "forest_1358.c", "west",
        AREA_PATH + "forest_1360.c", "east",
        AREA_PATH + "forest_1408.c", "southwest",
        AREA_PATH + "forest_1409.c", "south",
        AREA_PATH + "forest_1410.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1359 ) );
}

