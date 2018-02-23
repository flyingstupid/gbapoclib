/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1214) );
    set_long( get_long_by_id(1214) );


    set_exits(({
        AREA_PATH + "forest_1163.c", "northwest",
        AREA_PATH + "forest_1164.c", "north",
        AREA_PATH + "forest_1165.c", "northeast",
        AREA_PATH + "forest_1213.c", "west",
        AREA_PATH + "forest_1215.c", "east",
        AREA_PATH + "forest_1263.c", "southwest",
        AREA_PATH + "forest_1264.c", "south",
        AREA_PATH + "forest_1265.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1214 ) );
}

