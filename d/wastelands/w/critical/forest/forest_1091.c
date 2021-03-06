/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1091) );
    set_long( get_long_by_id(1091) );


    set_exits(({
        AREA_PATH + "forest_1040.c", "northwest",
        AREA_PATH + "forest_1041.c", "north",
        AREA_PATH + "forest_1042.c", "northeast",
        AREA_PATH + "forest_1090.c", "west",
        AREA_PATH + "forest_1092.c", "east",
        AREA_PATH + "forest_1140.c", "southwest",
        AREA_PATH + "forest_1141.c", "south",
        AREA_PATH + "forest_1142.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1091 ) );
}

