/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(844) );
    set_long( get_long_by_id(844) );


    set_exits(({
        AREA_PATH + "forest_793.c", "northwest",
        AREA_PATH + "forest_794.c", "north",
        AREA_PATH + "forest_795.c", "northeast",
        AREA_PATH + "forest_843.c", "west",
        AREA_PATH + "forest_845.c", "east",
        AREA_PATH + "forest_893.c", "southwest",
        AREA_PATH + "forest_894.c", "south",
        AREA_PATH + "forest_895.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 844 ) );
}

