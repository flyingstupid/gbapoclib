/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(618) );
    set_long( get_long_by_id(618) );


    set_exits(({
        AREA_PATH + "forest_567.c", "northwest",
        AREA_PATH + "forest_568.c", "north",
        AREA_PATH + "forest_569.c", "northeast",
        AREA_PATH + "forest_617.c", "west",
        AREA_PATH + "forest_619.c", "east",
        AREA_PATH + "forest_667.c", "southwest",
        AREA_PATH + "forest_668.c", "south",
        AREA_PATH + "forest_669.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 618 ) );
}

