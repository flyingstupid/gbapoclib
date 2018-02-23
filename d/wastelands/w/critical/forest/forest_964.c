/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(964) );
    set_long( get_long_by_id(964) );


    set_exits(({
        AREA_PATH + "forest_913.c", "northwest",
        AREA_PATH + "forest_914.c", "north",
        AREA_PATH + "forest_915.c", "northeast",
        AREA_PATH + "forest_963.c", "west",
        AREA_PATH + "forest_965.c", "east",
        AREA_PATH + "forest_1013.c", "southwest",
        AREA_PATH + "forest_1014.c", "south",
        AREA_PATH + "forest_1015.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 964 ) );
}

