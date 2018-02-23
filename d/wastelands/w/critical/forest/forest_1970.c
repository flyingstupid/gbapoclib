/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1970) );
    set_long( get_long_by_id(1970) );


    set_exits(({
        AREA_PATH + "forest_1919.c", "northwest",
        AREA_PATH + "forest_1920.c", "north",
        AREA_PATH + "forest_1921.c", "northeast",
        AREA_PATH + "forest_1969.c", "west",
        AREA_PATH + "forest_1971.c", "east",
        AREA_PATH + "forest_2019.c", "southwest",
        AREA_PATH + "forest_2020.c", "south",
        AREA_PATH + "forest_2021.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1970 ) );
}

