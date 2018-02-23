/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(626) );
    set_long( get_long_by_id(626) );


    set_exits(({
        AREA_PATH + "forest_575.c", "northwest",
        AREA_PATH + "forest_576.c", "north",
        AREA_PATH + "forest_577.c", "northeast",
        AREA_PATH + "forest_625.c", "west",
        AREA_PATH + "forest_627.c", "east",
        AREA_PATH + "forest_675.c", "southwest",
        AREA_PATH + "forest_676.c", "south",
        AREA_PATH + "forest_677.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 626 ) );
}

