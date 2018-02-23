/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(997) );
    set_long( get_long_by_id(997) );


    set_exits(({
        AREA_PATH + "forest_946.c", "northwest",
        AREA_PATH + "forest_947.c", "north",
        AREA_PATH + "forest_948.c", "northeast",
        AREA_PATH + "forest_996.c", "west",
        AREA_PATH + "forest_998.c", "east",
        AREA_PATH + "forest_1046.c", "southwest",
        AREA_PATH + "forest_1047.c", "south",
        AREA_PATH + "forest_1048.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 997 ) );
}

