/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(85) );
    set_long( get_long_by_id(85) );


    set_exits(({
        AREA_PATH + "forest_34.c", "northwest",
        AREA_PATH + "forest_35.c", "north",
        AREA_PATH + "forest_36.c", "northeast",
        AREA_PATH + "forest_84.c", "west",
        AREA_PATH + "forest_86.c", "east",
        AREA_PATH + "forest_134.c", "southwest",
        AREA_PATH + "forest_135.c", "south",
        AREA_PATH + "forest_136.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 85 ) );
}

