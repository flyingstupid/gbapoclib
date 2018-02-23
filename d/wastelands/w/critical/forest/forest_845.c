/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(845) );
    set_long( get_long_by_id(845) );


    set_exits(({
        AREA_PATH + "forest_794.c", "northwest",
        AREA_PATH + "forest_795.c", "north",
        AREA_PATH + "forest_796.c", "northeast",
        AREA_PATH + "forest_844.c", "west",
        AREA_PATH + "forest_846.c", "east",
        AREA_PATH + "forest_894.c", "southwest",
        AREA_PATH + "forest_895.c", "south",
        AREA_PATH + "forest_896.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 845 ) );
}

