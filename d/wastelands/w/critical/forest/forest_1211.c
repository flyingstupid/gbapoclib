/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1211) );
    set_long( get_long_by_id(1211) );


    set_exits(({
        AREA_PATH + "forest_1160.c", "northwest",
        AREA_PATH + "forest_1161.c", "north",
        AREA_PATH + "forest_1162.c", "northeast",
        AREA_PATH + "forest_1210.c", "west",
        AREA_PATH + "forest_1212.c", "east",
        AREA_PATH + "forest_1260.c", "southwest",
        AREA_PATH + "forest_1261.c", "south",
        AREA_PATH + "forest_1262.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1211 ) );
}

