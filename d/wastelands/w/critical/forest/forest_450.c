/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(450) );
    set_long( get_long_by_id(450) );


    set_exits(({
        AREA_PATH + "forest_400.c", "north",
        AREA_PATH + "forest_401.c", "northeast",
        AREA_PATH + "forest_451.c", "east",
        AREA_PATH + "forest_500.c", "south",
        AREA_PATH + "forest_501.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 450 ) );
}

