/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1020) );
    set_long( get_long_by_id(1020) );


    set_exits(({
        AREA_PATH + "forest_969.c", "northwest",
        AREA_PATH + "forest_970.c", "north",
        AREA_PATH + "forest_971.c", "northeast",
        AREA_PATH + "forest_1019.c", "west",
        AREA_PATH + "forest_1021.c", "east",
        AREA_PATH + "forest_1069.c", "southwest",
        AREA_PATH + "forest_1070.c", "south",
        AREA_PATH + "forest_1071.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1020 ) );
}

