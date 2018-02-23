/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1319) );
    set_long( get_long_by_id(1319) );


    set_exits(({
        AREA_PATH + "forest_1268.c", "northwest",
        AREA_PATH + "forest_1269.c", "north",
        AREA_PATH + "forest_1270.c", "northeast",
        AREA_PATH + "forest_1318.c", "west",
        AREA_PATH + "forest_1320.c", "east",
        AREA_PATH + "forest_1368.c", "southwest",
        AREA_PATH + "forest_1369.c", "south",
        AREA_PATH + "forest_1370.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1319 ) );
}

