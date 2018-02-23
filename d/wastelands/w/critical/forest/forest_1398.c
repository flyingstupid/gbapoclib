/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1398) );
    set_long( get_long_by_id(1398) );


    set_exits(({
        AREA_PATH + "forest_1347.c", "northwest",
        AREA_PATH + "forest_1348.c", "north",
        AREA_PATH + "forest_1349.c", "northeast",
        AREA_PATH + "forest_1397.c", "west",
        AREA_PATH + "forest_1399.c", "east",
        AREA_PATH + "forest_1447.c", "southwest",
        AREA_PATH + "forest_1448.c", "south",
        AREA_PATH + "forest_1449.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1398 ) );
}

