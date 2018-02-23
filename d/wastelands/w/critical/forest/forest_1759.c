/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1759) );
    set_long( get_long_by_id(1759) );


    set_exits(({
        AREA_PATH + "forest_1708.c", "northwest",
        AREA_PATH + "forest_1709.c", "north",
        AREA_PATH + "forest_1710.c", "northeast",
        AREA_PATH + "forest_1758.c", "west",
        AREA_PATH + "forest_1760.c", "east",
        AREA_PATH + "forest_1808.c", "southwest",
        AREA_PATH + "forest_1809.c", "south",
        AREA_PATH + "forest_1810.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1759 ) );
}

