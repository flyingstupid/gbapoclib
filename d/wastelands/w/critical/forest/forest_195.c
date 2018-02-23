/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(195) );
    set_long( get_long_by_id(195) );


    set_exits(({
        AREA_PATH + "forest_144.c", "northwest",
        AREA_PATH + "forest_145.c", "north",
        AREA_PATH + "forest_146.c", "northeast",
        AREA_PATH + "forest_194.c", "west",
        AREA_PATH + "forest_196.c", "east",
        AREA_PATH + "forest_244.c", "southwest",
        AREA_PATH + "forest_245.c", "south",
        AREA_PATH + "forest_246.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 195 ) );
}

