/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(264) );
    set_long( get_long_by_id(264) );


    set_exits(({
        AREA_PATH + "forest_213.c", "northwest",
        AREA_PATH + "forest_214.c", "north",
        AREA_PATH + "forest_215.c", "northeast",
        AREA_PATH + "forest_263.c", "west",
        AREA_PATH + "forest_265.c", "east",
        AREA_PATH + "forest_313.c", "southwest",
        AREA_PATH + "forest_314.c", "south",
        AREA_PATH + "forest_315.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 264 ) );
}

