/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(627) );
    set_long( get_long_by_id(627) );


    set_exits(({
        AREA_PATH + "forest_576.c", "northwest",
        AREA_PATH + "forest_577.c", "north",
        AREA_PATH + "forest_578.c", "northeast",
        AREA_PATH + "forest_626.c", "west",
        AREA_PATH + "forest_628.c", "east",
        AREA_PATH + "forest_676.c", "southwest",
        AREA_PATH + "forest_677.c", "south",
        AREA_PATH + "forest_678.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 627 ) );
}

