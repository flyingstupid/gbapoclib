/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(697) );
    set_long( get_long_by_id(697) );


    set_exits(({
        AREA_PATH + "forest_646.c", "northwest",
        AREA_PATH + "forest_647.c", "north",
        AREA_PATH + "forest_648.c", "northeast",
        AREA_PATH + "forest_696.c", "west",
        AREA_PATH + "forest_698.c", "east",
        AREA_PATH + "forest_746.c", "southwest",
        AREA_PATH + "forest_747.c", "south",
        AREA_PATH + "forest_748.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 697 ) );
}

