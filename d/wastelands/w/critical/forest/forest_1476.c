/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1476) );
    set_long( get_long_by_id(1476) );


    set_exits(({
        AREA_PATH + "forest_1425.c", "northwest",
        AREA_PATH + "forest_1426.c", "north",
        AREA_PATH + "forest_1427.c", "northeast",
        AREA_PATH + "forest_1475.c", "west",
        AREA_PATH + "forest_1477.c", "east",
        AREA_PATH + "forest_1525.c", "southwest",
        AREA_PATH + "forest_1526.c", "south",
        AREA_PATH + "forest_1527.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1476 ) );
}

