/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(954) );
    set_long( get_long_by_id(954) );


    set_exits(({
        AREA_PATH + "forest_903.c", "northwest",
        AREA_PATH + "forest_904.c", "north",
        AREA_PATH + "forest_905.c", "northeast",
        AREA_PATH + "forest_953.c", "west",
        AREA_PATH + "forest_955.c", "east",
        AREA_PATH + "forest_1003.c", "southwest",
        AREA_PATH + "forest_1004.c", "south",
        AREA_PATH + "forest_1005.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 954 ) );
}

