/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(562) );
    set_long( get_long_by_id(562) );


    set_exits(({
        AREA_PATH + "forest_511.c", "northwest",
        AREA_PATH + "forest_512.c", "north",
        AREA_PATH + "forest_513.c", "northeast",
        AREA_PATH + "forest_561.c", "west",
        AREA_PATH + "forest_563.c", "east",
        AREA_PATH + "forest_611.c", "southwest",
        AREA_PATH + "forest_612.c", "south",
        AREA_PATH + "forest_613.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 562 ) );
}

