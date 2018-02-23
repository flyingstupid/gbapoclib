/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1110) );
    set_long( get_long_by_id(1110) );


    set_exits(({
        AREA_PATH + "forest_1059.c", "northwest",
        AREA_PATH + "forest_1060.c", "north",
        AREA_PATH + "forest_1061.c", "northeast",
        AREA_PATH + "forest_1109.c", "west",
        AREA_PATH + "forest_1111.c", "east",
        AREA_PATH + "forest_1159.c", "southwest",
        AREA_PATH + "forest_1160.c", "south",
        AREA_PATH + "forest_1161.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1110 ) );
}

