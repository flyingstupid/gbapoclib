/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(847) );
    set_long( get_long_by_id(847) );


    set_exits(({
        AREA_PATH + "forest_796.c", "northwest",
        AREA_PATH + "forest_797.c", "north",
        AREA_PATH + "forest_798.c", "northeast",
        AREA_PATH + "forest_846.c", "west",
        AREA_PATH + "forest_848.c", "east",
        AREA_PATH + "forest_896.c", "southwest",
        AREA_PATH + "forest_897.c", "south",
        AREA_PATH + "forest_898.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 847 ) );
}

