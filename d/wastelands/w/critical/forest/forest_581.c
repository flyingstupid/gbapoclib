/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(581) );
    set_long( get_long_by_id(581) );


    set_exits(({
        AREA_PATH + "forest_530.c", "northwest",
        AREA_PATH + "forest_531.c", "north",
        AREA_PATH + "forest_532.c", "northeast",
        AREA_PATH + "forest_580.c", "west",
        AREA_PATH + "forest_582.c", "east",
        AREA_PATH + "forest_630.c", "southwest",
        AREA_PATH + "forest_631.c", "south",
        AREA_PATH + "forest_632.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 581 ) );
}

