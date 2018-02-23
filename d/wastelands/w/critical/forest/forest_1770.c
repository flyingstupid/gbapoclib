/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1770) );
    set_long( get_long_by_id(1770) );


    set_exits(({
        AREA_PATH + "forest_1719.c", "northwest",
        AREA_PATH + "forest_1720.c", "north",
        AREA_PATH + "forest_1721.c", "northeast",
        AREA_PATH + "forest_1769.c", "west",
        AREA_PATH + "forest_1771.c", "east",
        AREA_PATH + "forest_1819.c", "southwest",
        AREA_PATH + "forest_1820.c", "south",
        AREA_PATH + "forest_1821.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1770 ) );
}

