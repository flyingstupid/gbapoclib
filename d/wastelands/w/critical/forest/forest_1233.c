/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1233) );
    set_long( get_long_by_id(1233) );


    set_exits(({
        AREA_PATH + "forest_1182.c", "northwest",
        AREA_PATH + "forest_1183.c", "north",
        AREA_PATH + "forest_1184.c", "northeast",
        AREA_PATH + "forest_1232.c", "west",
        AREA_PATH + "forest_1234.c", "east",
        AREA_PATH + "forest_1282.c", "southwest",
        AREA_PATH + "forest_1283.c", "south",
        AREA_PATH + "forest_1284.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1233 ) );
}

