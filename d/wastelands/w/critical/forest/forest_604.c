/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(604) );
    set_long( get_long_by_id(604) );


    set_exits(({
        AREA_PATH + "forest_553.c", "northwest",
        AREA_PATH + "forest_554.c", "north",
        AREA_PATH + "forest_555.c", "northeast",
        AREA_PATH + "forest_603.c", "west",
        AREA_PATH + "forest_605.c", "east",
        AREA_PATH + "forest_653.c", "southwest",
        AREA_PATH + "forest_654.c", "south",
        AREA_PATH + "forest_655.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 604 ) );
}

