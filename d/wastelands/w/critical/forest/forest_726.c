/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(726) );
    set_long( get_long_by_id(726) );


    set_exits(({
        AREA_PATH + "forest_675.c", "northwest",
        AREA_PATH + "forest_676.c", "north",
        AREA_PATH + "forest_677.c", "northeast",
        AREA_PATH + "forest_725.c", "west",
        AREA_PATH + "forest_727.c", "east",
        AREA_PATH + "forest_775.c", "southwest",
        AREA_PATH + "forest_776.c", "south",
        AREA_PATH + "forest_777.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 726 ) );
}

