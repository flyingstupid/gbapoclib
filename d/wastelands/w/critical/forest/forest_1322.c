/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1322) );
    set_long( get_long_by_id(1322) );


    set_exits(({
        AREA_PATH + "forest_1271.c", "northwest",
        AREA_PATH + "forest_1272.c", "north",
        AREA_PATH + "forest_1273.c", "northeast",
        AREA_PATH + "forest_1321.c", "west",
        AREA_PATH + "forest_1323.c", "east",
        AREA_PATH + "forest_1371.c", "southwest",
        AREA_PATH + "forest_1372.c", "south",
        AREA_PATH + "forest_1373.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1322 ) );
}

