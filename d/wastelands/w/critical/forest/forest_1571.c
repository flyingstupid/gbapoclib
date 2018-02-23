/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1571) );
    set_long( get_long_by_id(1571) );


    set_exits(({
        AREA_PATH + "forest_1520.c", "northwest",
        AREA_PATH + "forest_1521.c", "north",
        AREA_PATH + "forest_1522.c", "northeast",
        AREA_PATH + "forest_1570.c", "west",
        AREA_PATH + "forest_1572.c", "east",
        AREA_PATH + "forest_1620.c", "southwest",
        AREA_PATH + "forest_1621.c", "south",
        AREA_PATH + "forest_1622.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1571 ) );
}

