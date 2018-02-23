/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(391) );
    set_long( get_long_by_id(391) );


    set_exits(({
        AREA_PATH + "forest_340.c", "northwest",
        AREA_PATH + "forest_341.c", "north",
        AREA_PATH + "forest_342.c", "northeast",
        AREA_PATH + "forest_390.c", "west",
        AREA_PATH + "forest_392.c", "east",
        AREA_PATH + "forest_440.c", "southwest",
        AREA_PATH + "forest_441.c", "south",
        AREA_PATH + "forest_442.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 391 ) );
}

