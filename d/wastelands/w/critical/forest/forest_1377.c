/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1377) );
    set_long( get_long_by_id(1377) );


    set_exits(({
        AREA_PATH + "forest_1326.c", "northwest",
        AREA_PATH + "forest_1327.c", "north",
        AREA_PATH + "forest_1328.c", "northeast",
        AREA_PATH + "forest_1376.c", "west",
        AREA_PATH + "forest_1378.c", "east",
        AREA_PATH + "forest_1426.c", "southwest",
        AREA_PATH + "forest_1427.c", "south",
        AREA_PATH + "forest_1428.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1377 ) );
}

