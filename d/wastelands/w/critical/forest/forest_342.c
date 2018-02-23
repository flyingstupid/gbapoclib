/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(342) );
    set_long( get_long_by_id(342) );


    set_exits(({
        AREA_PATH + "forest_291.c", "northwest",
        AREA_PATH + "forest_292.c", "north",
        AREA_PATH + "forest_293.c", "northeast",
        AREA_PATH + "forest_341.c", "west",
        AREA_PATH + "forest_343.c", "east",
        AREA_PATH + "forest_391.c", "southwest",
        AREA_PATH + "forest_392.c", "south",
        AREA_PATH + "forest_393.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 342 ) );
}

