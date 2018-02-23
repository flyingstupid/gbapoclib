/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(637) );
    set_long( get_long_by_id(637) );


    set_exits(({
        AREA_PATH + "forest_586.c", "northwest",
        AREA_PATH + "forest_587.c", "north",
        AREA_PATH + "forest_588.c", "northeast",
        AREA_PATH + "forest_636.c", "west",
        AREA_PATH + "forest_638.c", "east",
        AREA_PATH + "forest_686.c", "southwest",
        AREA_PATH + "forest_687.c", "south",
        AREA_PATH + "forest_688.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 637 ) );
}

