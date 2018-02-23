/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(437) );
    set_long( get_long_by_id(437) );


    set_exits(({
        AREA_PATH + "forest_386.c", "northwest",
        AREA_PATH + "forest_387.c", "north",
        AREA_PATH + "forest_388.c", "northeast",
        AREA_PATH + "forest_436.c", "west",
        AREA_PATH + "forest_438.c", "east",
        AREA_PATH + "forest_486.c", "southwest",
        AREA_PATH + "forest_487.c", "south",
        AREA_PATH + "forest_488.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 437 ) );
}

