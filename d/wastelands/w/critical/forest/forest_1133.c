/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1133) );
    set_long( get_long_by_id(1133) );


    set_exits(({
        AREA_PATH + "forest_1082.c", "northwest",
        AREA_PATH + "forest_1083.c", "north",
        AREA_PATH + "forest_1084.c", "northeast",
        AREA_PATH + "forest_1132.c", "west",
        AREA_PATH + "forest_1134.c", "east",
        AREA_PATH + "forest_1182.c", "southwest",
        AREA_PATH + "forest_1183.c", "south",
        AREA_PATH + "forest_1184.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1133 ) );
}

