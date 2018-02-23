/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1698) );
    set_long( get_long_by_id(1698) );


    set_exits(({
        AREA_PATH + "forest_1647.c", "northwest",
        AREA_PATH + "forest_1648.c", "north",
        AREA_PATH + "forest_1649.c", "northeast",
        AREA_PATH + "forest_1697.c", "west",
        AREA_PATH + "forest_1699.c", "east",
        AREA_PATH + "forest_1747.c", "southwest",
        AREA_PATH + "forest_1748.c", "south",
        AREA_PATH + "forest_1749.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1698 ) );
}

