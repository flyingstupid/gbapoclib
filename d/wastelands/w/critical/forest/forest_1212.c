/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1212) );
    set_long( get_long_by_id(1212) );


    set_exits(({
        AREA_PATH + "forest_1161.c", "northwest",
        AREA_PATH + "forest_1162.c", "north",
        AREA_PATH + "forest_1163.c", "northeast",
        AREA_PATH + "forest_1211.c", "west",
        AREA_PATH + "forest_1213.c", "east",
        AREA_PATH + "forest_1261.c", "southwest",
        AREA_PATH + "forest_1262.c", "south",
        AREA_PATH + "forest_1263.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1212 ) );
}

