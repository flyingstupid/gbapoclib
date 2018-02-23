/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(574) );
    set_long( get_long_by_id(574) );


    set_exits(({
        AREA_PATH + "forest_523.c", "northwest",
        AREA_PATH + "forest_524.c", "north",
        AREA_PATH + "forest_525.c", "northeast",
        AREA_PATH + "forest_573.c", "west",
        AREA_PATH + "forest_575.c", "east",
        AREA_PATH + "forest_623.c", "southwest",
        AREA_PATH + "forest_624.c", "south",
        AREA_PATH + "forest_625.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 574 ) );
}

