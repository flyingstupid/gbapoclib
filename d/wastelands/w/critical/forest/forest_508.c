/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(508) );
    set_long( get_long_by_id(508) );


    set_exits(({
        AREA_PATH + "forest_457.c", "northwest",
        AREA_PATH + "forest_458.c", "north",
        AREA_PATH + "forest_459.c", "northeast",
        AREA_PATH + "forest_507.c", "west",
        AREA_PATH + "forest_509.c", "east",
        AREA_PATH + "forest_557.c", "southwest",
        AREA_PATH + "forest_558.c", "south",
        AREA_PATH + "forest_559.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 508 ) );
}

