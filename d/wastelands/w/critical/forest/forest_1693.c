/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1693) );
    set_long( get_long_by_id(1693) );


    set_exits(({
        AREA_PATH + "forest_1642.c", "northwest",
        AREA_PATH + "forest_1643.c", "north",
        AREA_PATH + "forest_1644.c", "northeast",
        AREA_PATH + "forest_1692.c", "west",
        AREA_PATH + "forest_1694.c", "east",
        AREA_PATH + "forest_1742.c", "southwest",
        AREA_PATH + "forest_1743.c", "south",
        AREA_PATH + "forest_1744.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1693 ) );
}

