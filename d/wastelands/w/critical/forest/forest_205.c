/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(205) );
    set_long( get_long_by_id(205) );


    set_exits(({
        AREA_PATH + "forest_154.c", "northwest",
        AREA_PATH + "forest_155.c", "north",
        AREA_PATH + "forest_156.c", "northeast",
        AREA_PATH + "forest_204.c", "west",
        AREA_PATH + "forest_206.c", "east",
        AREA_PATH + "forest_254.c", "southwest",
        AREA_PATH + "forest_255.c", "south",
        AREA_PATH + "forest_256.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 205 ) );
}

