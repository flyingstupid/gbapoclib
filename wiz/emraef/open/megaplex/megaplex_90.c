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
    set_short( get_short_by_id(90) );
    set_long( get_long_by_id(90) );

    room_id = 90;

    set_exits(({
        AREA_PATH + "megaplex_80.c", "north",
        AREA_PATH + "megaplex_91.c", "east",
    }));

    set_room_type( get_room_scav_type( "cave", 90 ) );
}

