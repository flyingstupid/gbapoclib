/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1666) );
    set_long( get_long_by_id(1666) );


    set_exits(({
        AREA_PATH + "forest_1615.c", "northwest",
        AREA_PATH + "forest_1616.c", "north",
        AREA_PATH + "forest_1617.c", "northeast",
        AREA_PATH + "forest_1665.c", "west",
        AREA_PATH + "forest_1667.c", "east",
        AREA_PATH + "forest_1715.c", "southwest",
        AREA_PATH + "forest_1716.c", "south",
        AREA_PATH + "forest_1717.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1666 ) );
}

