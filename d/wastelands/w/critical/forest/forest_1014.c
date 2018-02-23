/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1014) );
    set_long( get_long_by_id(1014) );


    set_exits(({
        AREA_PATH + "forest_963.c", "northwest",
        AREA_PATH + "forest_964.c", "north",
        AREA_PATH + "forest_965.c", "northeast",
        AREA_PATH + "forest_1013.c", "west",
        AREA_PATH + "forest_1015.c", "east",
        AREA_PATH + "forest_1063.c", "southwest",
        AREA_PATH + "forest_1064.c", "south",
        AREA_PATH + "forest_1065.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1014 ) );
}

