/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(71) );
    set_long( get_long_by_id(71) );


    set_exits(({
        AREA_PATH + "forest_20.c", "northwest",
        AREA_PATH + "forest_21.c", "north",
        AREA_PATH + "forest_22.c", "northeast",
        AREA_PATH + "forest_70.c", "west",
        AREA_PATH + "forest_72.c", "east",
        AREA_PATH + "forest_120.c", "southwest",
        AREA_PATH + "forest_121.c", "south",
        AREA_PATH + "forest_122.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 71 ) );
}

