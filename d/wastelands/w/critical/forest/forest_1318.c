/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1318) );
    set_long( get_long_by_id(1318) );


    set_exits(({
        AREA_PATH + "forest_1267.c", "northwest",
        AREA_PATH + "forest_1268.c", "north",
        AREA_PATH + "forest_1269.c", "northeast",
        AREA_PATH + "forest_1317.c", "west",
        AREA_PATH + "forest_1319.c", "east",
        AREA_PATH + "forest_1367.c", "southwest",
        AREA_PATH + "forest_1368.c", "south",
        AREA_PATH + "forest_1369.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1318 ) );
}

