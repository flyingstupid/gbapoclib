/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(738) );
    set_long( get_long_by_id(738) );


    set_exits(({
        AREA_PATH + "forest_687.c", "northwest",
        AREA_PATH + "forest_688.c", "north",
        AREA_PATH + "forest_689.c", "northeast",
        AREA_PATH + "forest_737.c", "west",
        AREA_PATH + "forest_739.c", "east",
        AREA_PATH + "forest_787.c", "southwest",
        AREA_PATH + "forest_788.c", "south",
        AREA_PATH + "forest_789.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 738 ) );
}

