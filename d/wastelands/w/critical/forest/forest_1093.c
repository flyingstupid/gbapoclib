/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1093) );
    set_long( get_long_by_id(1093) );


    set_exits(({
        AREA_PATH + "forest_1042.c", "northwest",
        AREA_PATH + "forest_1043.c", "north",
        AREA_PATH + "forest_1044.c", "northeast",
        AREA_PATH + "forest_1092.c", "west",
        AREA_PATH + "forest_1094.c", "east",
        AREA_PATH + "forest_1142.c", "southwest",
        AREA_PATH + "forest_1143.c", "south",
        AREA_PATH + "forest_1144.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1093 ) );
}

