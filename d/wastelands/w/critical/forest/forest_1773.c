/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1773) );
    set_long( get_long_by_id(1773) );


    set_exits(({
        AREA_PATH + "forest_1722.c", "northwest",
        AREA_PATH + "forest_1723.c", "north",
        AREA_PATH + "forest_1724.c", "northeast",
        AREA_PATH + "forest_1772.c", "west",
        AREA_PATH + "forest_1774.c", "east",
        AREA_PATH + "forest_1822.c", "southwest",
        AREA_PATH + "forest_1823.c", "south",
        AREA_PATH + "forest_1824.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1773 ) );
}

