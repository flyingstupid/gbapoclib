/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1425) );
    set_long( get_long_by_id(1425) );


    set_exits(({
        AREA_PATH + "forest_1374.c", "northwest",
        AREA_PATH + "forest_1375.c", "north",
        AREA_PATH + "forest_1376.c", "northeast",
        AREA_PATH + "forest_1424.c", "west",
        AREA_PATH + "forest_1426.c", "east",
        AREA_PATH + "forest_1474.c", "southwest",
        AREA_PATH + "forest_1475.c", "south",
        AREA_PATH + "forest_1476.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1425 ) );
}

