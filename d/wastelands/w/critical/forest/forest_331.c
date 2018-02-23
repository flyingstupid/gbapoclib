/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(331) );
    set_long( get_long_by_id(331) );


    set_exits(({
        AREA_PATH + "forest_280.c", "northwest",
        AREA_PATH + "forest_281.c", "north",
        AREA_PATH + "forest_282.c", "northeast",
        AREA_PATH + "forest_330.c", "west",
        AREA_PATH + "forest_332.c", "east",
        AREA_PATH + "forest_380.c", "southwest",
        AREA_PATH + "forest_381.c", "south",
        AREA_PATH + "forest_382.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 331 ) );
}

