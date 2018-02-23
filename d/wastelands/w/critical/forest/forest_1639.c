/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1639) );
    set_long( get_long_by_id(1639) );


    set_exits(({
        AREA_PATH + "forest_1588.c", "northwest",
        AREA_PATH + "forest_1589.c", "north",
        AREA_PATH + "forest_1590.c", "northeast",
        AREA_PATH + "forest_1638.c", "west",
        AREA_PATH + "forest_1640.c", "east",
        AREA_PATH + "forest_1688.c", "southwest",
        AREA_PATH + "forest_1689.c", "south",
        AREA_PATH + "forest_1690.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1639 ) );
}

