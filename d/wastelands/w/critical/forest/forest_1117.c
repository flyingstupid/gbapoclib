/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1117) );
    set_long( get_long_by_id(1117) );


    set_exits(({
        AREA_PATH + "forest_1066.c", "northwest",
        AREA_PATH + "forest_1067.c", "north",
        AREA_PATH + "forest_1068.c", "northeast",
        AREA_PATH + "forest_1116.c", "west",
        AREA_PATH + "forest_1118.c", "east",
        AREA_PATH + "forest_1166.c", "southwest",
        AREA_PATH + "forest_1167.c", "south",
        AREA_PATH + "forest_1168.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1117 ) );
}

