/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(430) );
    set_long( get_long_by_id(430) );


    set_exits(({
        AREA_PATH + "forest_379.c", "northwest",
        AREA_PATH + "forest_380.c", "north",
        AREA_PATH + "forest_381.c", "northeast",
        AREA_PATH + "forest_429.c", "west",
        AREA_PATH + "forest_431.c", "east",
        AREA_PATH + "forest_479.c", "southwest",
        AREA_PATH + "forest_480.c", "south",
        AREA_PATH + "forest_481.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 430 ) );
}

