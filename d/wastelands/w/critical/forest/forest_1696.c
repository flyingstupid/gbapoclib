/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1696) );
    set_long( get_long_by_id(1696) );


    set_exits(({
        AREA_PATH + "forest_1645.c", "northwest",
        AREA_PATH + "forest_1646.c", "north",
        AREA_PATH + "forest_1647.c", "northeast",
        AREA_PATH + "forest_1695.c", "west",
        AREA_PATH + "forest_1697.c", "east",
        AREA_PATH + "forest_1745.c", "southwest",
        AREA_PATH + "forest_1746.c", "south",
        AREA_PATH + "forest_1747.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1696 ) );
}

