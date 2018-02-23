/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(792) );
    set_long( get_long_by_id(792) );


    set_exits(({
        AREA_PATH + "forest_741.c", "northwest",
        AREA_PATH + "forest_742.c", "north",
        AREA_PATH + "forest_743.c", "northeast",
        AREA_PATH + "forest_791.c", "west",
        AREA_PATH + "forest_793.c", "east",
        AREA_PATH + "forest_841.c", "southwest",
        AREA_PATH + "forest_842.c", "south",
        AREA_PATH + "forest_843.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 792 ) );
}

