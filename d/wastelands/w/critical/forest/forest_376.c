/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(376) );
    set_long( get_long_by_id(376) );


    set_exits(({
        AREA_PATH + "forest_325.c", "northwest",
        AREA_PATH + "forest_326.c", "north",
        AREA_PATH + "forest_327.c", "northeast",
        AREA_PATH + "forest_375.c", "west",
        AREA_PATH + "forest_377.c", "east",
        AREA_PATH + "forest_425.c", "southwest",
        AREA_PATH + "forest_426.c", "south",
        AREA_PATH + "forest_427.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 376 ) );
}

