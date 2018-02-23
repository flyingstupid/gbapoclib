/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(541) );
    set_long( get_long_by_id(541) );


    set_exits(({
        AREA_PATH + "forest_490.c", "northwest",
        AREA_PATH + "forest_491.c", "north",
        AREA_PATH + "forest_492.c", "northeast",
        AREA_PATH + "forest_540.c", "west",
        AREA_PATH + "forest_542.c", "east",
        AREA_PATH + "forest_590.c", "southwest",
        AREA_PATH + "forest_591.c", "south",
        AREA_PATH + "forest_592.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 541 ) );
}

