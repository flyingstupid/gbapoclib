/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 0, 1, 0 );
    set_short( get_short_by_id(687) );
    set_long( get_long_by_id(687) );


    set_exits(({
        AREA_PATH + "cave_637.c", "north",
        AREA_PATH + "cave_686.c", "west",
        AREA_PATH + "cave_688.c", "east",
        AREA_PATH + "cave_737.c", "south",
    }));

    set_room_type( get_room_scav_type( "cave", 687 ) );
}

