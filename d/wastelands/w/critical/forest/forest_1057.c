/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1057) );
    set_long( get_long_by_id(1057) );


    set_exits(({
        AREA_PATH + "forest_1006.c", "northwest",
        AREA_PATH + "forest_1007.c", "north",
        AREA_PATH + "forest_1008.c", "northeast",
        AREA_PATH + "forest_1056.c", "west",
        AREA_PATH + "forest_1058.c", "east",
        AREA_PATH + "forest_1106.c", "southwest",
        AREA_PATH + "forest_1107.c", "south",
        AREA_PATH + "forest_1108.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1057 ) );
}

