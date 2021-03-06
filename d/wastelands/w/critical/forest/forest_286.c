/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(286) );
    set_long( get_long_by_id(286) );


    set_exits(({
        AREA_PATH + "forest_235.c", "northwest",
        AREA_PATH + "forest_236.c", "north",
        AREA_PATH + "forest_237.c", "northeast",
        AREA_PATH + "forest_285.c", "west",
        AREA_PATH + "forest_287.c", "east",
        AREA_PATH + "forest_335.c", "southwest",
        AREA_PATH + "forest_336.c", "south",
        AREA_PATH + "forest_337.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 286 ) );
}

