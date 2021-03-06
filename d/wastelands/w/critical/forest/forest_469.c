/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(469) );
    set_long( get_long_by_id(469) );


    set_exits(({
        AREA_PATH + "forest_418.c", "northwest",
        AREA_PATH + "forest_419.c", "north",
        AREA_PATH + "forest_420.c", "northeast",
        AREA_PATH + "forest_468.c", "west",
        AREA_PATH + "forest_470.c", "east",
        AREA_PATH + "forest_518.c", "southwest",
        AREA_PATH + "forest_519.c", "south",
        AREA_PATH + "forest_520.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 469 ) );
}

