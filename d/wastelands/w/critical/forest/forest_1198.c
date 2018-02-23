/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1198) );
    set_long( get_long_by_id(1198) );


    set_exits(({
        AREA_PATH + "forest_1147.c", "northwest",
        AREA_PATH + "forest_1148.c", "north",
        AREA_PATH + "forest_1149.c", "northeast",
        AREA_PATH + "forest_1197.c", "west",
        AREA_PATH + "forest_1199.c", "east",
        AREA_PATH + "forest_1247.c", "southwest",
        AREA_PATH + "forest_1248.c", "south",
        AREA_PATH + "forest_1249.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1198 ) );
}

