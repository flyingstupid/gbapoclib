/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(939) );
    set_long( get_long_by_id(939) );


    set_exits(({
        AREA_PATH + "forest_888.c", "northwest",
        AREA_PATH + "forest_889.c", "north",
        AREA_PATH + "forest_890.c", "northeast",
        AREA_PATH + "forest_938.c", "west",
        AREA_PATH + "forest_940.c", "east",
        AREA_PATH + "forest_988.c", "southwest",
        AREA_PATH + "forest_989.c", "south",
        AREA_PATH + "forest_990.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 939 ) );
}

