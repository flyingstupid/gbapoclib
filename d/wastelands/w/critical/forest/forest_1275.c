/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1275) );
    set_long( get_long_by_id(1275) );


    set_exits(({
        AREA_PATH + "forest_1224.c", "northwest",
        AREA_PATH + "forest_1225.c", "north",
        AREA_PATH + "forest_1226.c", "northeast",
        AREA_PATH + "forest_1274.c", "west",
        AREA_PATH + "forest_1276.c", "east",
        AREA_PATH + "forest_1324.c", "southwest",
        AREA_PATH + "forest_1325.c", "south",
        AREA_PATH + "forest_1326.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1275 ) );
}

