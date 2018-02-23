/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1103) );
    set_long( get_long_by_id(1103) );


    set_exits(({
        AREA_PATH + "forest_1052.c", "northwest",
        AREA_PATH + "forest_1053.c", "north",
        AREA_PATH + "forest_1054.c", "northeast",
        AREA_PATH + "forest_1102.c", "west",
        AREA_PATH + "forest_1104.c", "east",
        AREA_PATH + "forest_1152.c", "southwest",
        AREA_PATH + "forest_1153.c", "south",
        AREA_PATH + "forest_1154.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1103 ) );
}

