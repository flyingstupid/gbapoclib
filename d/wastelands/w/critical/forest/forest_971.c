/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(971) );
    set_long( get_long_by_id(971) );


    set_exits(({
        AREA_PATH + "forest_920.c", "northwest",
        AREA_PATH + "forest_921.c", "north",
        AREA_PATH + "forest_922.c", "northeast",
        AREA_PATH + "forest_970.c", "west",
        AREA_PATH + "forest_972.c", "east",
        AREA_PATH + "forest_1020.c", "southwest",
        AREA_PATH + "forest_1021.c", "south",
        AREA_PATH + "forest_1022.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 971 ) );
}

