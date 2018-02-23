/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1342) );
    set_long( get_long_by_id(1342) );


    set_exits(({
        AREA_PATH + "forest_1291.c", "northwest",
        AREA_PATH + "forest_1292.c", "north",
        AREA_PATH + "forest_1293.c", "northeast",
        AREA_PATH + "forest_1341.c", "west",
        AREA_PATH + "forest_1343.c", "east",
        AREA_PATH + "forest_1391.c", "southwest",
        AREA_PATH + "forest_1392.c", "south",
        AREA_PATH + "forest_1393.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1342 ) );
}

