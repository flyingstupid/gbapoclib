/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(652) );
    set_long( get_long_by_id(652) );


    set_exits(({
        AREA_PATH + "forest_601.c", "northwest",
        AREA_PATH + "forest_602.c", "north",
        AREA_PATH + "forest_603.c", "northeast",
        AREA_PATH + "forest_651.c", "west",
        AREA_PATH + "forest_653.c", "east",
        AREA_PATH + "forest_701.c", "southwest",
        AREA_PATH + "forest_702.c", "south",
        AREA_PATH + "forest_703.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 652 ) );
}

