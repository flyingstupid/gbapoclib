/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1423) );
    set_long( get_long_by_id(1423) );


    set_exits(({
        AREA_PATH + "forest_1372.c", "northwest",
        AREA_PATH + "forest_1373.c", "north",
        AREA_PATH + "forest_1374.c", "northeast",
        AREA_PATH + "forest_1422.c", "west",
        AREA_PATH + "forest_1424.c", "east",
        AREA_PATH + "forest_1472.c", "southwest",
        AREA_PATH + "forest_1473.c", "south",
        AREA_PATH + "forest_1474.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1423 ) );
}

