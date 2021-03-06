/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(307) );
    set_long( get_long_by_id(307) );


    set_exits(({
        AREA_PATH + "forest_256.c", "northwest",
        AREA_PATH + "forest_257.c", "north",
        AREA_PATH + "forest_258.c", "northeast",
        AREA_PATH + "forest_306.c", "west",
        AREA_PATH + "forest_308.c", "east",
        AREA_PATH + "forest_356.c", "southwest",
        AREA_PATH + "forest_357.c", "south",
        AREA_PATH + "forest_358.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 307 ) );
}

