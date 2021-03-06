/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1052) );
    set_long( get_long_by_id(1052) );


    set_exits(({
        AREA_PATH + "forest_1001.c", "northwest",
        AREA_PATH + "forest_1002.c", "north",
        AREA_PATH + "forest_1003.c", "northeast",
        AREA_PATH + "forest_1051.c", "west",
        AREA_PATH + "forest_1053.c", "east",
        AREA_PATH + "forest_1101.c", "southwest",
        AREA_PATH + "forest_1102.c", "south",
        AREA_PATH + "forest_1103.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1052 ) );
}

