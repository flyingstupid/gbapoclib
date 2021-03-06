/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(877) );
    set_long( get_long_by_id(877) );


    set_exits(({
        AREA_PATH + "forest_826.c", "northwest",
        AREA_PATH + "forest_827.c", "north",
        AREA_PATH + "forest_828.c", "northeast",
        AREA_PATH + "forest_876.c", "west",
        AREA_PATH + "forest_878.c", "east",
        AREA_PATH + "forest_926.c", "southwest",
        AREA_PATH + "forest_927.c", "south",
        AREA_PATH + "forest_928.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 877 ) );
}

