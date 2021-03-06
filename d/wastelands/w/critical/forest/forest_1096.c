/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1096) );
    set_long( get_long_by_id(1096) );


    set_exits(({
        AREA_PATH + "forest_1045.c", "northwest",
        AREA_PATH + "forest_1046.c", "north",
        AREA_PATH + "forest_1047.c", "northeast",
        AREA_PATH + "forest_1095.c", "west",
        AREA_PATH + "forest_1097.c", "east",
        AREA_PATH + "forest_1145.c", "southwest",
        AREA_PATH + "forest_1146.c", "south",
        AREA_PATH + "forest_1147.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1096 ) );
}

