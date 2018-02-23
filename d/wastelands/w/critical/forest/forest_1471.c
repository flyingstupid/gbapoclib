/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1471) );
    set_long( get_long_by_id(1471) );


    set_exits(({
        AREA_PATH + "forest_1420.c", "northwest",
        AREA_PATH + "forest_1421.c", "north",
        AREA_PATH + "forest_1422.c", "northeast",
        AREA_PATH + "forest_1470.c", "west",
        AREA_PATH + "forest_1472.c", "east",
        AREA_PATH + "forest_1520.c", "southwest",
        AREA_PATH + "forest_1521.c", "south",
        AREA_PATH + "forest_1522.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1471 ) );
}

