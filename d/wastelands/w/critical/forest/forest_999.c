/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(999) );
    set_long( get_long_by_id(999) );


    set_exits(({
        AREA_PATH + "forest_948.c", "northwest",
        AREA_PATH + "forest_949.c", "north",
        AREA_PATH + "forest_998.c", "west",
        AREA_PATH + "forest_1048.c", "southwest",
        AREA_PATH + "forest_1049.c", "south",
    }));

    set_room_type( get_room_scav_type( "forest", 999 ) );
}

