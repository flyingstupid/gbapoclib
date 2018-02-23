/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(87) );
    set_long( get_long_by_id(87) );


    set_exits(({
        AREA_PATH + "forest_36.c", "northwest",
        AREA_PATH + "forest_37.c", "north",
        AREA_PATH + "forest_38.c", "northeast",
        AREA_PATH + "forest_86.c", "west",
        AREA_PATH + "forest_88.c", "east",
        AREA_PATH + "forest_136.c", "southwest",
        AREA_PATH + "forest_137.c", "south",
        AREA_PATH + "forest_138.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 87 ) );
}

