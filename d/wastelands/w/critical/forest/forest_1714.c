/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1714) );
    set_long( get_long_by_id(1714) );


    set_exits(({
        AREA_PATH + "forest_1663.c", "northwest",
        AREA_PATH + "forest_1664.c", "north",
        AREA_PATH + "forest_1665.c", "northeast",
        AREA_PATH + "forest_1713.c", "west",
        AREA_PATH + "forest_1715.c", "east",
        AREA_PATH + "forest_1763.c", "southwest",
        AREA_PATH + "forest_1764.c", "south",
        AREA_PATH + "forest_1765.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1714 ) );
}

