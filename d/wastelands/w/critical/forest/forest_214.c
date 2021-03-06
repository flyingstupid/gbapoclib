/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(214) );
    set_long( get_long_by_id(214) );


    set_exits(({
        AREA_PATH + "forest_163.c", "northwest",
        AREA_PATH + "forest_164.c", "north",
        AREA_PATH + "forest_165.c", "northeast",
        AREA_PATH + "forest_213.c", "west",
        AREA_PATH + "forest_215.c", "east",
        AREA_PATH + "forest_263.c", "southwest",
        AREA_PATH + "forest_264.c", "south",
        AREA_PATH + "forest_265.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 214 ) );
}

