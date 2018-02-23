/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1440) );
    set_long( get_long_by_id(1440) );


    set_exits(({
        AREA_PATH + "forest_1389.c", "northwest",
        AREA_PATH + "forest_1390.c", "north",
        AREA_PATH + "forest_1391.c", "northeast",
        AREA_PATH + "forest_1439.c", "west",
        AREA_PATH + "forest_1441.c", "east",
        AREA_PATH + "forest_1489.c", "southwest",
        AREA_PATH + "forest_1490.c", "south",
        AREA_PATH + "forest_1491.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1440 ) );
}

