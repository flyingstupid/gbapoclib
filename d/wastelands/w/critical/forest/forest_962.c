/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(962) );
    set_long( get_long_by_id(962) );


    set_exits(({
        AREA_PATH + "forest_911.c", "northwest",
        AREA_PATH + "forest_912.c", "north",
        AREA_PATH + "forest_913.c", "northeast",
        AREA_PATH + "forest_961.c", "west",
        AREA_PATH + "forest_963.c", "east",
        AREA_PATH + "forest_1011.c", "southwest",
        AREA_PATH + "forest_1012.c", "south",
        AREA_PATH + "forest_1013.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 962 ) );
}

