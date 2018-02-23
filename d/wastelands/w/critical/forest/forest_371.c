/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(371) );
    set_long( get_long_by_id(371) );


    set_exits(({
        AREA_PATH + "forest_320.c", "northwest",
        AREA_PATH + "forest_321.c", "north",
        AREA_PATH + "forest_322.c", "northeast",
        AREA_PATH + "forest_370.c", "west",
        AREA_PATH + "forest_372.c", "east",
        AREA_PATH + "forest_420.c", "southwest",
        AREA_PATH + "forest_421.c", "south",
        AREA_PATH + "forest_422.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 371 ) );
}

