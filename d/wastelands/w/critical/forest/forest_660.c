/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(660) );
    set_long( get_long_by_id(660) );


    set_exits(({
        AREA_PATH + "forest_609.c", "northwest",
        AREA_PATH + "forest_610.c", "north",
        AREA_PATH + "forest_611.c", "northeast",
        AREA_PATH + "forest_659.c", "west",
        AREA_PATH + "forest_661.c", "east",
        AREA_PATH + "forest_709.c", "southwest",
        AREA_PATH + "forest_710.c", "south",
        AREA_PATH + "forest_711.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 660 ) );
}

