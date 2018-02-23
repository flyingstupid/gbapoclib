/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1384) );
    set_long( get_long_by_id(1384) );


    set_exits(({
        AREA_PATH + "forest_1333.c", "northwest",
        AREA_PATH + "forest_1334.c", "north",
        AREA_PATH + "forest_1335.c", "northeast",
        AREA_PATH + "forest_1383.c", "west",
        AREA_PATH + "forest_1385.c", "east",
        AREA_PATH + "forest_1433.c", "southwest",
        AREA_PATH + "forest_1434.c", "south",
        AREA_PATH + "forest_1435.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1384 ) );
}

