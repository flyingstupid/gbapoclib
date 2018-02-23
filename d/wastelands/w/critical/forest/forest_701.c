/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(701) );
    set_long( get_long_by_id(701) );


    set_exits(({
        AREA_PATH + "forest_650.c", "northwest",
        AREA_PATH + "forest_651.c", "north",
        AREA_PATH + "forest_652.c", "northeast",
        AREA_PATH + "forest_700.c", "west",
        AREA_PATH + "forest_702.c", "east",
        AREA_PATH + "forest_750.c", "southwest",
        AREA_PATH + "forest_751.c", "south",
        AREA_PATH + "forest_752.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 701 ) );
}

