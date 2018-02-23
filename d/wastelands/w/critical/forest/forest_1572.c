/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1572) );
    set_long( get_long_by_id(1572) );


    set_exits(({
        AREA_PATH + "forest_1521.c", "northwest",
        AREA_PATH + "forest_1522.c", "north",
        AREA_PATH + "forest_1523.c", "northeast",
        AREA_PATH + "forest_1571.c", "west",
        AREA_PATH + "forest_1573.c", "east",
        AREA_PATH + "forest_1621.c", "southwest",
        AREA_PATH + "forest_1622.c", "south",
        AREA_PATH + "forest_1623.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1572 ) );
}

