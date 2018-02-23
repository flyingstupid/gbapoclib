/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 0, 1, 0 );
    set_short( get_short_by_id(72) );
    set_long( get_long_by_id(72) );


    set_exits(({
        AREA_PATH + "cave_62.c", "north",
        AREA_PATH + "cave_71.c", "west",
        AREA_PATH + "cave_73.c", "east",
        AREA_PATH + "cave_82.c", "south",
    }));

    set_room_type( get_room_scav_type( "cave", 72 ) );
}

