/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(919) );
    set_long( get_long_by_id(919) );


    set_exits(({
        AREA_PATH + "forest_868.c", "northwest",
        AREA_PATH + "forest_869.c", "north",
        AREA_PATH + "forest_870.c", "northeast",
        AREA_PATH + "forest_918.c", "west",
        AREA_PATH + "forest_920.c", "east",
        AREA_PATH + "forest_968.c", "southwest",
        AREA_PATH + "forest_969.c", "south",
        AREA_PATH + "forest_970.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 919 ) );
}

