/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1291) );
    set_long( get_long_by_id(1291) );


    set_exits(({
        AREA_PATH + "forest_1240.c", "northwest",
        AREA_PATH + "forest_1241.c", "north",
        AREA_PATH + "forest_1242.c", "northeast",
        AREA_PATH + "forest_1290.c", "west",
        AREA_PATH + "forest_1292.c", "east",
        AREA_PATH + "forest_1340.c", "southwest",
        AREA_PATH + "forest_1341.c", "south",
        AREA_PATH + "forest_1342.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1291 ) );
}

