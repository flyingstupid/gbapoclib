/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1138) );
    set_long( get_long_by_id(1138) );


    set_exits(({
        AREA_PATH + "forest_1087.c", "northwest",
        AREA_PATH + "forest_1088.c", "north",
        AREA_PATH + "forest_1089.c", "northeast",
        AREA_PATH + "forest_1137.c", "west",
        AREA_PATH + "forest_1139.c", "east",
        AREA_PATH + "forest_1187.c", "southwest",
        AREA_PATH + "forest_1188.c", "south",
        AREA_PATH + "forest_1189.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1138 ) );
}

