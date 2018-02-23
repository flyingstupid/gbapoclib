/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(98) );
    set_long( get_long_by_id(98) );


    set_exits(({
        AREA_PATH + "forest_47.c", "northwest",
        AREA_PATH + "forest_48.c", "north",
        AREA_PATH + "forest_49.c", "northeast",
        AREA_PATH + "forest_97.c", "west",
        AREA_PATH + "forest_99.c", "east",
        AREA_PATH + "forest_147.c", "southwest",
        AREA_PATH + "forest_148.c", "south",
        AREA_PATH + "forest_149.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 98 ) );
}

