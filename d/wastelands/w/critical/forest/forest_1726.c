/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1726) );
    set_long( get_long_by_id(1726) );


    set_exits(({
        AREA_PATH + "forest_1675.c", "northwest",
        AREA_PATH + "forest_1676.c", "north",
        AREA_PATH + "forest_1677.c", "northeast",
        AREA_PATH + "forest_1725.c", "west",
        AREA_PATH + "forest_1727.c", "east",
        AREA_PATH + "forest_1775.c", "southwest",
        AREA_PATH + "forest_1776.c", "south",
        AREA_PATH + "forest_1777.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1726 ) );
}

