/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(261) );
    set_long( get_long_by_id(261) );


    set_exits(({
        AREA_PATH + "forest_210.c", "northwest",
        AREA_PATH + "forest_211.c", "north",
        AREA_PATH + "forest_212.c", "northeast",
        AREA_PATH + "forest_260.c", "west",
        AREA_PATH + "forest_262.c", "east",
        AREA_PATH + "forest_310.c", "southwest",
        AREA_PATH + "forest_311.c", "south",
        AREA_PATH + "forest_312.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 261 ) );
}

