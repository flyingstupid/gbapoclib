/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1205) );
    set_long( get_long_by_id(1205) );


    set_exits(({
        AREA_PATH + "forest_1154.c", "northwest",
        AREA_PATH + "forest_1155.c", "north",
        AREA_PATH + "forest_1156.c", "northeast",
        AREA_PATH + "forest_1204.c", "west",
        AREA_PATH + "forest_1206.c", "east",
        AREA_PATH + "forest_1254.c", "southwest",
        AREA_PATH + "forest_1255.c", "south",
        AREA_PATH + "forest_1256.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1205 ) );
}

