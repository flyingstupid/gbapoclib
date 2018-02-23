/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(228) );
    set_long( get_long_by_id(228) );


    set_exits(({
        AREA_PATH + "forest_177.c", "northwest",
        AREA_PATH + "forest_178.c", "north",
        AREA_PATH + "forest_179.c", "northeast",
        AREA_PATH + "forest_227.c", "west",
        AREA_PATH + "forest_229.c", "east",
        AREA_PATH + "forest_277.c", "southwest",
        AREA_PATH + "forest_278.c", "south",
        AREA_PATH + "forest_279.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 228 ) );
}

