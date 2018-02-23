/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(796) );
    set_long( get_long_by_id(796) );


    set_exits(({
        AREA_PATH + "forest_745.c", "northwest",
        AREA_PATH + "forest_746.c", "north",
        AREA_PATH + "forest_747.c", "northeast",
        AREA_PATH + "forest_795.c", "west",
        AREA_PATH + "forest_797.c", "east",
        AREA_PATH + "forest_845.c", "southwest",
        AREA_PATH + "forest_846.c", "south",
        AREA_PATH + "forest_847.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 796 ) );
}

