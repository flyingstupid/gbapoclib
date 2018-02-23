/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(84) );
    set_long( get_long_by_id(84) );


    set_exits(({
        AREA_PATH + "forest_33.c", "northwest",
        AREA_PATH + "forest_34.c", "north",
        AREA_PATH + "forest_35.c", "northeast",
        AREA_PATH + "forest_83.c", "west",
        AREA_PATH + "forest_85.c", "east",
        AREA_PATH + "forest_133.c", "southwest",
        AREA_PATH + "forest_134.c", "south",
        AREA_PATH + "forest_135.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 84 ) );
}

