/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1108) );
    set_long( get_long_by_id(1108) );


    set_exits(({
        AREA_PATH + "forest_1057.c", "northwest",
        AREA_PATH + "forest_1058.c", "north",
        AREA_PATH + "forest_1059.c", "northeast",
        AREA_PATH + "forest_1107.c", "west",
        AREA_PATH + "forest_1109.c", "east",
        AREA_PATH + "forest_1157.c", "southwest",
        AREA_PATH + "forest_1158.c", "south",
        AREA_PATH + "forest_1159.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1108 ) );
}

