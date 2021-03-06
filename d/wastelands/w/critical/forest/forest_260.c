/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(260) );
    set_long( get_long_by_id(260) );


    set_exits(({
        AREA_PATH + "forest_209.c", "northwest",
        AREA_PATH + "forest_210.c", "north",
        AREA_PATH + "forest_211.c", "northeast",
        AREA_PATH + "forest_259.c", "west",
        AREA_PATH + "forest_261.c", "east",
        AREA_PATH + "forest_309.c", "southwest",
        AREA_PATH + "forest_310.c", "south",
        AREA_PATH + "forest_311.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 260 ) );
}

