/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1683) );
    set_long( get_long_by_id(1683) );


    set_exits(({
        AREA_PATH + "forest_1632.c", "northwest",
        AREA_PATH + "forest_1633.c", "north",
        AREA_PATH + "forest_1634.c", "northeast",
        AREA_PATH + "forest_1682.c", "west",
        AREA_PATH + "forest_1684.c", "east",
        AREA_PATH + "forest_1732.c", "southwest",
        AREA_PATH + "forest_1733.c", "south",
        AREA_PATH + "forest_1734.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1683 ) );
}

