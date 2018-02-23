/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(761) );
    set_long( get_long_by_id(761) );


    set_exits(({
        AREA_PATH + "forest_710.c", "northwest",
        AREA_PATH + "forest_711.c", "north",
        AREA_PATH + "forest_712.c", "northeast",
        AREA_PATH + "forest_760.c", "west",
        AREA_PATH + "forest_762.c", "east",
        AREA_PATH + "forest_810.c", "southwest",
        AREA_PATH + "forest_811.c", "south",
        AREA_PATH + "forest_812.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 761 ) );
}

