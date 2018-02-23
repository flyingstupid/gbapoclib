/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1146) );
    set_long( get_long_by_id(1146) );


    set_exits(({
        AREA_PATH + "forest_1095.c", "northwest",
        AREA_PATH + "forest_1096.c", "north",
        AREA_PATH + "forest_1097.c", "northeast",
        AREA_PATH + "forest_1145.c", "west",
        AREA_PATH + "forest_1147.c", "east",
        AREA_PATH + "forest_1195.c", "southwest",
        AREA_PATH + "forest_1196.c", "south",
        AREA_PATH + "forest_1197.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1146 ) );
}

