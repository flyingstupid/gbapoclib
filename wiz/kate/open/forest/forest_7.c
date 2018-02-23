/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 5, 0, 0 );
    set_short( get_short_by_id(7) );
    set_long( get_long_by_id(7) );


    set_exits(({
        AREA_PATH + "forest_3.c", "northwest",
        AREA_PATH + "forest_4.c", "north",
        AREA_PATH + "forest_5.c", "northeast",
        AREA_PATH + "forest_6.c", "west",
        AREA_PATH + "forest_8.c", "east",
    }));

    set_room_type("forest");
}

