/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1933) );
    set_long( get_long_by_id(1933) );


    set_exits(({
        AREA_PATH + "forest_1882.c", "northwest",
        AREA_PATH + "forest_1883.c", "north",
        AREA_PATH + "forest_1884.c", "northeast",
        AREA_PATH + "forest_1932.c", "west",
        AREA_PATH + "forest_1934.c", "east",
        AREA_PATH + "forest_1982.c", "southwest",
        AREA_PATH + "forest_1983.c", "south",
        AREA_PATH + "forest_1984.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1933 ) );
}

