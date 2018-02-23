/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(868) );
    set_long( get_long_by_id(868) );


    set_exits(({
        AREA_PATH + "forest_817.c", "northwest",
        AREA_PATH + "forest_818.c", "north",
        AREA_PATH + "forest_819.c", "northeast",
        AREA_PATH + "forest_867.c", "west",
        AREA_PATH + "forest_869.c", "east",
        AREA_PATH + "forest_917.c", "southwest",
        AREA_PATH + "forest_918.c", "south",
        AREA_PATH + "forest_919.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 868 ) );
}

