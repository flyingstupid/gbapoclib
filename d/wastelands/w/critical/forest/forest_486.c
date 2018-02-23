/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(486) );
    set_long( get_long_by_id(486) );


    set_exits(({
        AREA_PATH + "forest_435.c", "northwest",
        AREA_PATH + "forest_436.c", "north",
        AREA_PATH + "forest_437.c", "northeast",
        AREA_PATH + "forest_485.c", "west",
        AREA_PATH + "forest_487.c", "east",
        AREA_PATH + "forest_535.c", "southwest",
        AREA_PATH + "forest_536.c", "south",
        AREA_PATH + "forest_537.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 486 ) );
}

