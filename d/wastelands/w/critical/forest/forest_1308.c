/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1308) );
    set_long( get_long_by_id(1308) );


    set_exits(({
        AREA_PATH + "forest_1257.c", "northwest",
        AREA_PATH + "forest_1258.c", "north",
        AREA_PATH + "forest_1259.c", "northeast",
        AREA_PATH + "forest_1307.c", "west",
        AREA_PATH + "forest_1309.c", "east",
        AREA_PATH + "forest_1357.c", "southwest",
        AREA_PATH + "forest_1358.c", "south",
        AREA_PATH + "forest_1359.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1308 ) );
}

