/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1090) );
    set_long( get_long_by_id(1090) );


    set_exits(({
        AREA_PATH + "forest_1039.c", "northwest",
        AREA_PATH + "forest_1040.c", "north",
        AREA_PATH + "forest_1041.c", "northeast",
        AREA_PATH + "forest_1089.c", "west",
        AREA_PATH + "forest_1091.c", "east",
        AREA_PATH + "forest_1139.c", "southwest",
        AREA_PATH + "forest_1140.c", "south",
        AREA_PATH + "forest_1141.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1090 ) );
}

