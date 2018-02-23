/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1186) );
    set_long( get_long_by_id(1186) );


    set_exits(({
        AREA_PATH + "forest_1135.c", "northwest",
        AREA_PATH + "forest_1136.c", "north",
        AREA_PATH + "forest_1137.c", "northeast",
        AREA_PATH + "forest_1185.c", "west",
        AREA_PATH + "forest_1187.c", "east",
        AREA_PATH + "forest_1235.c", "southwest",
        AREA_PATH + "forest_1236.c", "south",
        AREA_PATH + "forest_1237.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1186 ) );
}

