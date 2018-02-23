/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(922) );
    set_long( get_long_by_id(922) );


    set_exits(({
        AREA_PATH + "forest_871.c", "northwest",
        AREA_PATH + "forest_872.c", "north",
        AREA_PATH + "forest_873.c", "northeast",
        AREA_PATH + "forest_921.c", "west",
        AREA_PATH + "forest_923.c", "east",
        AREA_PATH + "forest_971.c", "southwest",
        AREA_PATH + "forest_972.c", "south",
        AREA_PATH + "forest_973.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 922 ) );
}

