/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(435) );
    set_long( get_long_by_id(435) );


    set_exits(({
        AREA_PATH + "forest_384.c", "northwest",
        AREA_PATH + "forest_385.c", "north",
        AREA_PATH + "forest_386.c", "northeast",
        AREA_PATH + "forest_434.c", "west",
        AREA_PATH + "forest_436.c", "east",
        AREA_PATH + "forest_484.c", "southwest",
        AREA_PATH + "forest_485.c", "south",
        AREA_PATH + "forest_486.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 435 ) );
}

