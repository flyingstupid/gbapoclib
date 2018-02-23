/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(765) );
    set_long( get_long_by_id(765) );


    set_exits(({
        AREA_PATH + "forest_714.c", "northwest",
        AREA_PATH + "forest_715.c", "north",
        AREA_PATH + "forest_716.c", "northeast",
        AREA_PATH + "forest_764.c", "west",
        AREA_PATH + "forest_766.c", "east",
        AREA_PATH + "forest_814.c", "southwest",
        AREA_PATH + "forest_815.c", "south",
        AREA_PATH + "forest_816.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 765 ) );
}

