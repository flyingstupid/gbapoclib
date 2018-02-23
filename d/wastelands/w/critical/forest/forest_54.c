/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(54) );
    set_long( get_long_by_id(54) );


    set_exits(({
        AREA_PATH + "forest_3.c", "northwest",
        AREA_PATH + "forest_4.c", "north",
        AREA_PATH + "forest_5.c", "northeast",
        AREA_PATH + "forest_53.c", "west",
        AREA_PATH + "forest_55.c", "east",
        AREA_PATH + "forest_103.c", "southwest",
        AREA_PATH + "forest_104.c", "south",
        AREA_PATH + "forest_105.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 54 ) );
}

