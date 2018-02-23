/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1136) );
    set_long( get_long_by_id(1136) );


    set_exits(({
        AREA_PATH + "forest_1085.c", "northwest",
        AREA_PATH + "forest_1086.c", "north",
        AREA_PATH + "forest_1087.c", "northeast",
        AREA_PATH + "forest_1135.c", "west",
        AREA_PATH + "forest_1137.c", "east",
        AREA_PATH + "forest_1185.c", "southwest",
        AREA_PATH + "forest_1186.c", "south",
        AREA_PATH + "forest_1187.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1136 ) );
}

