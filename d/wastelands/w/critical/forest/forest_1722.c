/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1722) );
    set_long( get_long_by_id(1722) );


    set_exits(({
        AREA_PATH + "forest_1671.c", "northwest",
        AREA_PATH + "forest_1672.c", "north",
        AREA_PATH + "forest_1673.c", "northeast",
        AREA_PATH + "forest_1721.c", "west",
        AREA_PATH + "forest_1723.c", "east",
        AREA_PATH + "forest_1771.c", "southwest",
        AREA_PATH + "forest_1772.c", "south",
        AREA_PATH + "forest_1773.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1722 ) );
}

