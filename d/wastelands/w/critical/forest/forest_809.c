/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(809) );
    set_long( get_long_by_id(809) );


    set_exits(({
        AREA_PATH + "forest_758.c", "northwest",
        AREA_PATH + "forest_759.c", "north",
        AREA_PATH + "forest_760.c", "northeast",
        AREA_PATH + "forest_808.c", "west",
        AREA_PATH + "forest_810.c", "east",
        AREA_PATH + "forest_858.c", "southwest",
        AREA_PATH + "forest_859.c", "south",
        AREA_PATH + "forest_860.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 809 ) );
}

