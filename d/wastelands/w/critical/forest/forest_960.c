/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(960) );
    set_long( get_long_by_id(960) );


    set_exits(({
        AREA_PATH + "forest_909.c", "northwest",
        AREA_PATH + "forest_910.c", "north",
        AREA_PATH + "forest_911.c", "northeast",
        AREA_PATH + "forest_959.c", "west",
        AREA_PATH + "forest_961.c", "east",
        AREA_PATH + "forest_1009.c", "southwest",
        AREA_PATH + "forest_1010.c", "south",
        AREA_PATH + "forest_1011.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 960 ) );
}

