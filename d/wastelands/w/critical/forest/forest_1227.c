/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1227) );
    set_long( get_long_by_id(1227) );


    set_exits(({
        AREA_PATH + "forest_1176.c", "northwest",
        AREA_PATH + "forest_1177.c", "north",
        AREA_PATH + "forest_1178.c", "northeast",
        AREA_PATH + "forest_1226.c", "west",
        AREA_PATH + "forest_1228.c", "east",
        AREA_PATH + "forest_1276.c", "southwest",
        AREA_PATH + "forest_1277.c", "south",
        AREA_PATH + "forest_1278.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1227 ) );
}

