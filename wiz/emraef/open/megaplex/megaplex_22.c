/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

int room_id;

void reset(status arg) {

    common_reset(arg);

    if (arg) return;

    set_weather( 0, 1, 0 );
    set_short( get_short_by_id(22) );
    set_long( get_long_by_id(22) );

    room_id = 22;

    set_exits(({
        AREA_PATH + "megaplex_12.c", "north",
        AREA_PATH + "megaplex_32.c", "south",
        AREA_PATH + "megaplex_21.c", "west",
    }));

    set_room_type( get_room_scav_type( "cave", 22 ) );
}

