/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2467) );
    set_long( get_long_by_id(2467) );


    set_exits(({
        AREA_PATH + "forest_2416.c", "northwest",
        AREA_PATH + "forest_2417.c", "north",
        AREA_PATH + "forest_2418.c", "northeast",
        AREA_PATH + "forest_2466.c", "west",
        AREA_PATH + "forest_2468.c", "east",
    }));

    set_room_type( get_room_scav_type( "forest", 2467 ) );
}

