/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(669) );
    set_long( get_long_by_id(669) );


    set_exits(({
        AREA_PATH + "forest_618.c", "northwest",
        AREA_PATH + "forest_619.c", "north",
        AREA_PATH + "forest_620.c", "northeast",
        AREA_PATH + "forest_668.c", "west",
        AREA_PATH + "forest_670.c", "east",
        AREA_PATH + "forest_718.c", "southwest",
        AREA_PATH + "forest_719.c", "south",
        AREA_PATH + "forest_720.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 669 ) );
}

