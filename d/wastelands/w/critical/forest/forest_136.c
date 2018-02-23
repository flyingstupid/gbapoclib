/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(136) );
    set_long( get_long_by_id(136) );


    set_exits(({
        AREA_PATH + "forest_85.c", "northwest",
        AREA_PATH + "forest_86.c", "north",
        AREA_PATH + "forest_87.c", "northeast",
        AREA_PATH + "forest_135.c", "west",
        AREA_PATH + "forest_137.c", "east",
        AREA_PATH + "forest_185.c", "southwest",
        AREA_PATH + "forest_186.c", "south",
        AREA_PATH + "forest_187.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 136 ) );
}

