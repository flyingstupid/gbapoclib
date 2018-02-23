/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(155) );
    set_long( get_long_by_id(155) );


    set_exits(({
        AREA_PATH + "forest_104.c", "northwest",
        AREA_PATH + "forest_105.c", "north",
        AREA_PATH + "forest_106.c", "northeast",
        AREA_PATH + "forest_154.c", "west",
        AREA_PATH + "forest_156.c", "east",
        AREA_PATH + "forest_204.c", "southwest",
        AREA_PATH + "forest_205.c", "south",
        AREA_PATH + "forest_206.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 155 ) );
}

