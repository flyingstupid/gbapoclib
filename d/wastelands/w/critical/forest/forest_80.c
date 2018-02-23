/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(80) );
    set_long( get_long_by_id(80) );


    set_exits(({
        AREA_PATH + "forest_29.c", "northwest",
        AREA_PATH + "forest_30.c", "north",
        AREA_PATH + "forest_31.c", "northeast",
        AREA_PATH + "forest_79.c", "west",
        AREA_PATH + "forest_81.c", "east",
        AREA_PATH + "forest_129.c", "southwest",
        AREA_PATH + "forest_130.c", "south",
        AREA_PATH + "forest_131.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 80 ) );
}

