/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(659) );
    set_long( get_long_by_id(659) );


    set_exits(({
        AREA_PATH + "forest_608.c", "northwest",
        AREA_PATH + "forest_609.c", "north",
        AREA_PATH + "forest_610.c", "northeast",
        AREA_PATH + "forest_658.c", "west",
        AREA_PATH + "forest_660.c", "east",
        AREA_PATH + "forest_708.c", "southwest",
        AREA_PATH + "forest_709.c", "south",
        AREA_PATH + "forest_710.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 659 ) );
}

