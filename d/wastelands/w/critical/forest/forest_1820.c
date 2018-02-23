/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1820) );
    set_long( get_long_by_id(1820) );


    set_exits(({
        AREA_PATH + "forest_1769.c", "northwest",
        AREA_PATH + "forest_1770.c", "north",
        AREA_PATH + "forest_1771.c", "northeast",
        AREA_PATH + "forest_1819.c", "west",
        AREA_PATH + "forest_1821.c", "east",
        AREA_PATH + "forest_1869.c", "southwest",
        AREA_PATH + "forest_1870.c", "south",
        AREA_PATH + "forest_1871.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1820 ) );
}

