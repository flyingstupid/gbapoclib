/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(220) );
    set_long( get_long_by_id(220) );


    set_exits(({
        AREA_PATH + "forest_169.c", "northwest",
        AREA_PATH + "forest_170.c", "north",
        AREA_PATH + "forest_171.c", "northeast",
        AREA_PATH + "forest_219.c", "west",
        AREA_PATH + "forest_221.c", "east",
        AREA_PATH + "forest_269.c", "southwest",
        AREA_PATH + "forest_270.c", "south",
        AREA_PATH + "forest_271.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 220 ) );
}

