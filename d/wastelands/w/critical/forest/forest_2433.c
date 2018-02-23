/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(2433) );
    set_long( get_long_by_id(2433) );


    set_exits(({
        AREA_PATH + "forest_2382.c", "northwest",
        AREA_PATH + "forest_2383.c", "north",
        AREA_PATH + "forest_2384.c", "northeast",
        AREA_PATH + "forest_2432.c", "west",
        AREA_PATH + "forest_2434.c", "east",
        AREA_PATH + "forest_2482.c", "southwest",
        AREA_PATH + "forest_2483.c", "south",
        AREA_PATH + "forest_2484.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 2433 ) );
}

