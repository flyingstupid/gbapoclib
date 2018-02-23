/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1464) );
    set_long( get_long_by_id(1464) );


    set_exits(({
        AREA_PATH + "forest_1413.c", "northwest",
        AREA_PATH + "forest_1414.c", "north",
        AREA_PATH + "forest_1415.c", "northeast",
        AREA_PATH + "forest_1463.c", "west",
        AREA_PATH + "forest_1465.c", "east",
        AREA_PATH + "forest_1513.c", "southwest",
        AREA_PATH + "forest_1514.c", "south",
        AREA_PATH + "forest_1515.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1464 ) );
}

