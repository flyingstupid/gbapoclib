/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(341) );
    set_long( get_long_by_id(341) );


    set_exits(({
        AREA_PATH + "forest_290.c", "northwest",
        AREA_PATH + "forest_291.c", "north",
        AREA_PATH + "forest_292.c", "northeast",
        AREA_PATH + "forest_340.c", "west",
        AREA_PATH + "forest_342.c", "east",
        AREA_PATH + "forest_390.c", "southwest",
        AREA_PATH + "forest_391.c", "south",
        AREA_PATH + "forest_392.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 341 ) );
}

