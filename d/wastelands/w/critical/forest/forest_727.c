/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(727) );
    set_long( get_long_by_id(727) );


    set_exits(({
        AREA_PATH + "forest_676.c", "northwest",
        AREA_PATH + "forest_677.c", "north",
        AREA_PATH + "forest_678.c", "northeast",
        AREA_PATH + "forest_726.c", "west",
        AREA_PATH + "forest_728.c", "east",
        AREA_PATH + "forest_776.c", "southwest",
        AREA_PATH + "forest_777.c", "south",
        AREA_PATH + "forest_778.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 727 ) );
}

