/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1428) );
    set_long( get_long_by_id(1428) );


    set_exits(({
        AREA_PATH + "forest_1377.c", "northwest",
        AREA_PATH + "forest_1378.c", "north",
        AREA_PATH + "forest_1379.c", "northeast",
        AREA_PATH + "forest_1427.c", "west",
        AREA_PATH + "forest_1429.c", "east",
        AREA_PATH + "forest_1477.c", "southwest",
        AREA_PATH + "forest_1478.c", "south",
        AREA_PATH + "forest_1479.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1428 ) );
}

