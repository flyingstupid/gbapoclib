/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(934) );
    set_long( get_long_by_id(934) );


    set_exits(({
        AREA_PATH + "forest_883.c", "northwest",
        AREA_PATH + "forest_884.c", "north",
        AREA_PATH + "forest_885.c", "northeast",
        AREA_PATH + "forest_933.c", "west",
        AREA_PATH + "forest_935.c", "east",
        AREA_PATH + "forest_983.c", "southwest",
        AREA_PATH + "forest_984.c", "south",
        AREA_PATH + "forest_985.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 934 ) );
}

