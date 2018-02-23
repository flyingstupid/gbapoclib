/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1126) );
    set_long( get_long_by_id(1126) );


    set_exits(({
        AREA_PATH + "forest_1075.c", "northwest",
        AREA_PATH + "forest_1076.c", "north",
        AREA_PATH + "forest_1077.c", "northeast",
        AREA_PATH + "forest_1125.c", "west",
        AREA_PATH + "forest_1127.c", "east",
        AREA_PATH + "forest_1175.c", "southwest",
        AREA_PATH + "forest_1176.c", "south",
        AREA_PATH + "forest_1177.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1126 ) );
}

