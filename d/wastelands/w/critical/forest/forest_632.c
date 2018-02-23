/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(632) );
    set_long( get_long_by_id(632) );


    set_exits(({
        AREA_PATH + "forest_581.c", "northwest",
        AREA_PATH + "forest_582.c", "north",
        AREA_PATH + "forest_583.c", "northeast",
        AREA_PATH + "forest_631.c", "west",
        AREA_PATH + "forest_633.c", "east",
        AREA_PATH + "forest_681.c", "southwest",
        AREA_PATH + "forest_682.c", "south",
        AREA_PATH + "forest_683.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 632 ) );
}

