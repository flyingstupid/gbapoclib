/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(477) );
    set_long( get_long_by_id(477) );


    set_exits(({
        AREA_PATH + "forest_426.c", "northwest",
        AREA_PATH + "forest_427.c", "north",
        AREA_PATH + "forest_428.c", "northeast",
        AREA_PATH + "forest_476.c", "west",
        AREA_PATH + "forest_478.c", "east",
        AREA_PATH + "forest_526.c", "southwest",
        AREA_PATH + "forest_527.c", "south",
        AREA_PATH + "forest_528.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 477 ) );
}

