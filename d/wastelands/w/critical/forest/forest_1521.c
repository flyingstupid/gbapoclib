/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1521) );
    set_long( get_long_by_id(1521) );


    set_exits(({
        AREA_PATH + "forest_1470.c", "northwest",
        AREA_PATH + "forest_1471.c", "north",
        AREA_PATH + "forest_1472.c", "northeast",
        AREA_PATH + "forest_1520.c", "west",
        AREA_PATH + "forest_1522.c", "east",
        AREA_PATH + "forest_1570.c", "southwest",
        AREA_PATH + "forest_1571.c", "south",
        AREA_PATH + "forest_1572.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1521 ) );
}

