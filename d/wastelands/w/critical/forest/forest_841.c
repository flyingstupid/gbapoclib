/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(841) );
    set_long( get_long_by_id(841) );


    set_exits(({
        AREA_PATH + "forest_790.c", "northwest",
        AREA_PATH + "forest_791.c", "north",
        AREA_PATH + "forest_792.c", "northeast",
        AREA_PATH + "forest_840.c", "west",
        AREA_PATH + "forest_842.c", "east",
        AREA_PATH + "forest_890.c", "southwest",
        AREA_PATH + "forest_891.c", "south",
        AREA_PATH + "forest_892.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 841 ) );
}

