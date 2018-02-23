/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1753) );
    set_long( get_long_by_id(1753) );


    set_exits(({
        AREA_PATH + "forest_1702.c", "northwest",
        AREA_PATH + "forest_1703.c", "north",
        AREA_PATH + "forest_1704.c", "northeast",
        AREA_PATH + "forest_1752.c", "west",
        AREA_PATH + "forest_1754.c", "east",
        AREA_PATH + "forest_1802.c", "southwest",
        AREA_PATH + "forest_1803.c", "south",
        AREA_PATH + "forest_1804.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1753 ) );
}

