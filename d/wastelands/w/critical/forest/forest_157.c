/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(157) );
    set_long( get_long_by_id(157) );


    set_exits(({
        AREA_PATH + "forest_106.c", "northwest",
        AREA_PATH + "forest_107.c", "north",
        AREA_PATH + "forest_108.c", "northeast",
        AREA_PATH + "forest_156.c", "west",
        AREA_PATH + "forest_158.c", "east",
        AREA_PATH + "forest_206.c", "southwest",
        AREA_PATH + "forest_207.c", "south",
        AREA_PATH + "forest_208.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 157 ) );
}

