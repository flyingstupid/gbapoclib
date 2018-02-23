/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(472) );
    set_long( get_long_by_id(472) );


    set_exits(({
        AREA_PATH + "forest_421.c", "northwest",
        AREA_PATH + "forest_422.c", "north",
        AREA_PATH + "forest_423.c", "northeast",
        AREA_PATH + "forest_471.c", "west",
        AREA_PATH + "forest_473.c", "east",
        AREA_PATH + "forest_521.c", "southwest",
        AREA_PATH + "forest_522.c", "south",
        AREA_PATH + "forest_523.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 472 ) );
}
