/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(580) );
    set_long( get_long_by_id(580) );


    set_exits(({
        AREA_PATH + "forest_529.c", "northwest",
        AREA_PATH + "forest_530.c", "north",
        AREA_PATH + "forest_531.c", "northeast",
        AREA_PATH + "forest_579.c", "west",
        AREA_PATH + "forest_581.c", "east",
        AREA_PATH + "forest_629.c", "southwest",
        AREA_PATH + "forest_630.c", "south",
        AREA_PATH + "forest_631.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 580 ) );
}

