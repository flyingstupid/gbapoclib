/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1403) );
    set_long( get_long_by_id(1403) );


    set_exits(({
        AREA_PATH + "forest_1352.c", "northwest",
        AREA_PATH + "forest_1353.c", "north",
        AREA_PATH + "forest_1354.c", "northeast",
        AREA_PATH + "forest_1402.c", "west",
        AREA_PATH + "forest_1404.c", "east",
        AREA_PATH + "forest_1452.c", "southwest",
        AREA_PATH + "forest_1453.c", "south",
        AREA_PATH + "forest_1454.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1403 ) );
}

