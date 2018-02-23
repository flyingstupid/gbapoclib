/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1066) );
    set_long( get_long_by_id(1066) );


    set_exits(({
        AREA_PATH + "forest_1015.c", "northwest",
        AREA_PATH + "forest_1016.c", "north",
        AREA_PATH + "forest_1017.c", "northeast",
        AREA_PATH + "forest_1065.c", "west",
        AREA_PATH + "forest_1067.c", "east",
        AREA_PATH + "forest_1115.c", "southwest",
        AREA_PATH + "forest_1116.c", "south",
        AREA_PATH + "forest_1117.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1066 ) );
}

