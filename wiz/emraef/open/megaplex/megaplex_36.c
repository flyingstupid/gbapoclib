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
    set_short( get_short_by_id(36) );
    set_long( get_long_by_id(36) );

    room_id = 36;

    set_exits(({
        AREA_PATH + "megaplex_46.c", "south",
        AREA_PATH + "megaplex_35.c", "west",
        AREA_PATH + "megaplex_37.c", "east",
        AREA_PATH + "megaplex_45.c", "southwest",
    }));

    set_room_type( get_room_scav_type( "cave", 36 ) );
}

