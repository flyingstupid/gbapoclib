/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1302) );
    set_long( get_long_by_id(1302) );


    set_exits(({
        AREA_PATH + "forest_1251.c", "northwest",
        AREA_PATH + "forest_1252.c", "north",
        AREA_PATH + "forest_1253.c", "northeast",
        AREA_PATH + "forest_1301.c", "west",
        AREA_PATH + "forest_1303.c", "east",
        AREA_PATH + "forest_1351.c", "southwest",
        AREA_PATH + "forest_1352.c", "south",
        AREA_PATH + "forest_1353.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1302 ) );
}

