/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(949) );
    set_long( get_long_by_id(949) );


    set_exits(({
        AREA_PATH + "forest_898.c", "northwest",
        AREA_PATH + "forest_899.c", "north",
        AREA_PATH + "forest_948.c", "west",
        AREA_PATH + "forest_998.c", "southwest",
        AREA_PATH + "forest_999.c", "south",
    }));

    set_room_type( get_room_scav_type( "forest", 949 ) );
}

