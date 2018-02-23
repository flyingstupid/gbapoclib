/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(356) );
    set_long( get_long_by_id(356) );


    set_exits(({
        AREA_PATH + "forest_305.c", "northwest",
        AREA_PATH + "forest_306.c", "north",
        AREA_PATH + "forest_307.c", "northeast",
        AREA_PATH + "forest_355.c", "west",
        AREA_PATH + "forest_357.c", "east",
        AREA_PATH + "forest_405.c", "southwest",
        AREA_PATH + "forest_406.c", "south",
        AREA_PATH + "forest_407.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 356 ) );
}

