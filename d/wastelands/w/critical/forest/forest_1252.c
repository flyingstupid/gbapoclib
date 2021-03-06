/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1252) );
    set_long( get_long_by_id(1252) );


    set_exits(({
        AREA_PATH + "forest_1201.c", "northwest",
        AREA_PATH + "forest_1202.c", "north",
        AREA_PATH + "forest_1203.c", "northeast",
        AREA_PATH + "forest_1251.c", "west",
        AREA_PATH + "forest_1253.c", "east",
        AREA_PATH + "forest_1301.c", "southwest",
        AREA_PATH + "forest_1302.c", "south",
        AREA_PATH + "forest_1303.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1252 ) );
}

