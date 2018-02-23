/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(617) );
    set_long( get_long_by_id(617) );


    set_exits(({
        AREA_PATH + "forest_566.c", "northwest",
        AREA_PATH + "forest_567.c", "north",
        AREA_PATH + "forest_568.c", "northeast",
        AREA_PATH + "forest_616.c", "west",
        AREA_PATH + "forest_618.c", "east",
        AREA_PATH + "forest_666.c", "southwest",
        AREA_PATH + "forest_667.c", "south",
        AREA_PATH + "forest_668.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 617 ) );
}

