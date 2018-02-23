/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1193) );
    set_long( get_long_by_id(1193) );


    set_exits(({
        AREA_PATH + "forest_1142.c", "northwest",
        AREA_PATH + "forest_1143.c", "north",
        AREA_PATH + "forest_1144.c", "northeast",
        AREA_PATH + "forest_1192.c", "west",
        AREA_PATH + "forest_1194.c", "east",
        AREA_PATH + "forest_1242.c", "southwest",
        AREA_PATH + "forest_1243.c", "south",
        AREA_PATH + "forest_1244.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1193 ) );
}

