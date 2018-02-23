/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(603) );
    set_long( get_long_by_id(603) );


    set_exits(({
        AREA_PATH + "forest_552.c", "northwest",
        AREA_PATH + "forest_553.c", "north",
        AREA_PATH + "forest_554.c", "northeast",
        AREA_PATH + "forest_602.c", "west",
        AREA_PATH + "forest_604.c", "east",
        AREA_PATH + "forest_652.c", "southwest",
        AREA_PATH + "forest_653.c", "south",
        AREA_PATH + "forest_654.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 603 ) );
}

