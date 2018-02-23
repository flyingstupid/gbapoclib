/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1216) );
    set_long( get_long_by_id(1216) );


    set_exits(({
        AREA_PATH + "forest_1165.c", "northwest",
        AREA_PATH + "forest_1166.c", "north",
        AREA_PATH + "forest_1167.c", "northeast",
        AREA_PATH + "forest_1215.c", "west",
        AREA_PATH + "forest_1217.c", "east",
        AREA_PATH + "forest_1265.c", "southwest",
        AREA_PATH + "forest_1266.c", "south",
        AREA_PATH + "forest_1267.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1216 ) );
}

