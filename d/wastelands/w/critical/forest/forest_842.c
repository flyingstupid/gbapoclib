/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(842) );
    set_long( get_long_by_id(842) );


    set_exits(({
        AREA_PATH + "forest_791.c", "northwest",
        AREA_PATH + "forest_792.c", "north",
        AREA_PATH + "forest_793.c", "northeast",
        AREA_PATH + "forest_841.c", "west",
        AREA_PATH + "forest_843.c", "east",
        AREA_PATH + "forest_891.c", "southwest",
        AREA_PATH + "forest_892.c", "south",
        AREA_PATH + "forest_893.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 842 ) );
}

