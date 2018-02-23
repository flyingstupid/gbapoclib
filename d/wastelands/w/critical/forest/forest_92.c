/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(92) );
    set_long( get_long_by_id(92) );


    set_exits(({
        AREA_PATH + "forest_41.c", "northwest",
        AREA_PATH + "forest_42.c", "north",
        AREA_PATH + "forest_43.c", "northeast",
        AREA_PATH + "forest_91.c", "west",
        AREA_PATH + "forest_93.c", "east",
        AREA_PATH + "forest_141.c", "southwest",
        AREA_PATH + "forest_142.c", "south",
        AREA_PATH + "forest_143.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 92 ) );
}

