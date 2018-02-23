/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(925) );
    set_long( get_long_by_id(925) );


    set_exits(({
        AREA_PATH + "forest_874.c", "northwest",
        AREA_PATH + "forest_875.c", "north",
        AREA_PATH + "forest_876.c", "northeast",
        AREA_PATH + "forest_924.c", "west",
        AREA_PATH + "forest_926.c", "east",
        AREA_PATH + "forest_974.c", "southwest",
        AREA_PATH + "forest_975.c", "south",
        AREA_PATH + "forest_976.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 925 ) );
}

