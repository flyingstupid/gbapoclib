/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(957) );
    set_long( get_long_by_id(957) );


    set_exits(({
        AREA_PATH + "forest_906.c", "northwest",
        AREA_PATH + "forest_907.c", "north",
        AREA_PATH + "forest_908.c", "northeast",
        AREA_PATH + "forest_956.c", "west",
        AREA_PATH + "forest_958.c", "east",
        AREA_PATH + "forest_1006.c", "southwest",
        AREA_PATH + "forest_1007.c", "south",
        AREA_PATH + "forest_1008.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 957 ) );
}

