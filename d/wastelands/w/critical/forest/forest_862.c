/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(862) );
    set_long( get_long_by_id(862) );


    set_exits(({
        AREA_PATH + "forest_811.c", "northwest",
        AREA_PATH + "forest_812.c", "north",
        AREA_PATH + "forest_813.c", "northeast",
        AREA_PATH + "forest_861.c", "west",
        AREA_PATH + "forest_863.c", "east",
        AREA_PATH + "forest_911.c", "southwest",
        AREA_PATH + "forest_912.c", "south",
        AREA_PATH + "forest_913.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 862 ) );
}

