/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1229) );
    set_long( get_long_by_id(1229) );


    set_exits(({
        AREA_PATH + "forest_1178.c", "northwest",
        AREA_PATH + "forest_1179.c", "north",
        AREA_PATH + "forest_1180.c", "northeast",
        AREA_PATH + "forest_1228.c", "west",
        AREA_PATH + "forest_1230.c", "east",
        AREA_PATH + "forest_1278.c", "southwest",
        AREA_PATH + "forest_1279.c", "south",
        AREA_PATH + "forest_1280.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1229 ) );
}

