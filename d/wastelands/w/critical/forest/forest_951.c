/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(951) );
    set_long( get_long_by_id(951) );


    set_exits(({
        AREA_PATH + "forest_900.c", "northwest",
        AREA_PATH + "forest_901.c", "north",
        AREA_PATH + "forest_902.c", "northeast",
        AREA_PATH + "forest_950.c", "west",
        AREA_PATH + "forest_952.c", "east",
        AREA_PATH + "forest_1000.c", "southwest",
        AREA_PATH + "forest_1001.c", "south",
        AREA_PATH + "forest_1002.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 951 ) );
}

