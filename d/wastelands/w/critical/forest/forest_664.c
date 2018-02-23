/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(664) );
    set_long( get_long_by_id(664) );


    set_exits(({
        AREA_PATH + "forest_613.c", "northwest",
        AREA_PATH + "forest_614.c", "north",
        AREA_PATH + "forest_615.c", "northeast",
        AREA_PATH + "forest_663.c", "west",
        AREA_PATH + "forest_665.c", "east",
        AREA_PATH + "forest_713.c", "southwest",
        AREA_PATH + "forest_714.c", "south",
        AREA_PATH + "forest_715.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 664 ) );
}

