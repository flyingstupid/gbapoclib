/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1134) );
    set_long( get_long_by_id(1134) );


    set_exits(({
        AREA_PATH + "forest_1083.c", "northwest",
        AREA_PATH + "forest_1084.c", "north",
        AREA_PATH + "forest_1085.c", "northeast",
        AREA_PATH + "forest_1133.c", "west",
        AREA_PATH + "forest_1135.c", "east",
        AREA_PATH + "forest_1183.c", "southwest",
        AREA_PATH + "forest_1184.c", "south",
        AREA_PATH + "forest_1185.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1134 ) );
}

