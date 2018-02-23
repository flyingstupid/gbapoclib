/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(685) );
    set_long( get_long_by_id(685) );


    set_exits(({
        AREA_PATH + "forest_634.c", "northwest",
        AREA_PATH + "forest_635.c", "north",
        AREA_PATH + "forest_636.c", "northeast",
        AREA_PATH + "forest_684.c", "west",
        AREA_PATH + "forest_686.c", "east",
        AREA_PATH + "forest_734.c", "southwest",
        AREA_PATH + "forest_735.c", "south",
        AREA_PATH + "forest_736.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 685 ) );
}

