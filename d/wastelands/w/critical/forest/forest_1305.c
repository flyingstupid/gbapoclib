/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1305) );
    set_long( get_long_by_id(1305) );


    set_exits(({
        AREA_PATH + "forest_1254.c", "northwest",
        AREA_PATH + "forest_1255.c", "north",
        AREA_PATH + "forest_1256.c", "northeast",
        AREA_PATH + "forest_1304.c", "west",
        AREA_PATH + "forest_1306.c", "east",
        AREA_PATH + "forest_1354.c", "southwest",
        AREA_PATH + "forest_1355.c", "south",
        AREA_PATH + "forest_1356.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1305 ) );
}

