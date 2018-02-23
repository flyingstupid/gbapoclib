/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1715) );
    set_long( get_long_by_id(1715) );


    set_exits(({
        AREA_PATH + "forest_1664.c", "northwest",
        AREA_PATH + "forest_1665.c", "north",
        AREA_PATH + "forest_1666.c", "northeast",
        AREA_PATH + "forest_1714.c", "west",
        AREA_PATH + "forest_1716.c", "east",
        AREA_PATH + "forest_1764.c", "southwest",
        AREA_PATH + "forest_1765.c", "south",
        AREA_PATH + "forest_1766.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1715 ) );
}

