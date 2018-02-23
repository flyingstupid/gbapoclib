/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(748) );
    set_long( get_long_by_id(748) );


    set_exits(({
        AREA_PATH + "forest_697.c", "northwest",
        AREA_PATH + "forest_698.c", "north",
        AREA_PATH + "forest_699.c", "northeast",
        AREA_PATH + "forest_747.c", "west",
        AREA_PATH + "forest_749.c", "east",
        AREA_PATH + "forest_797.c", "southwest",
        AREA_PATH + "forest_798.c", "south",
        AREA_PATH + "forest_799.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 748 ) );
}

