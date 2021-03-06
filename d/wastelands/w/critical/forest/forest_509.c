/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(509) );
    set_long( get_long_by_id(509) );


    set_exits(({
        AREA_PATH + "forest_458.c", "northwest",
        AREA_PATH + "forest_459.c", "north",
        AREA_PATH + "forest_460.c", "northeast",
        AREA_PATH + "forest_508.c", "west",
        AREA_PATH + "forest_510.c", "east",
        AREA_PATH + "forest_558.c", "southwest",
        AREA_PATH + "forest_559.c", "south",
        AREA_PATH + "forest_560.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 509 ) );
}

