/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(984) );
    set_long( get_long_by_id(984) );


    set_exits(({
        AREA_PATH + "forest_933.c", "northwest",
        AREA_PATH + "forest_934.c", "north",
        AREA_PATH + "forest_935.c", "northeast",
        AREA_PATH + "forest_983.c", "west",
        AREA_PATH + "forest_985.c", "east",
        AREA_PATH + "forest_1033.c", "southwest",
        AREA_PATH + "forest_1034.c", "south",
        AREA_PATH + "forest_1035.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 984 ) );
}

