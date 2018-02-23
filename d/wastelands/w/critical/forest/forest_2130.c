/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2130) );
    set_long( get_long_by_id(2130) );


    set_exits(({
        AREA_PATH + "forest_2079.c", "northwest",
        AREA_PATH + "forest_2080.c", "north",
        AREA_PATH + "forest_2081.c", "northeast",
        AREA_PATH + "forest_2129.c", "west",
        AREA_PATH + "forest_2131.c", "east",
        AREA_PATH + "forest_2179.c", "southwest",
        AREA_PATH + "forest_2180.c", "south",
        AREA_PATH + "forest_2181.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2130 ) );
}

