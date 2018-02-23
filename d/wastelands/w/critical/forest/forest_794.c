/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(794) );
    set_long( get_long_by_id(794) );


    set_exits(({
        AREA_PATH + "forest_743.c", "northwest",
        AREA_PATH + "forest_744.c", "north",
        AREA_PATH + "forest_745.c", "northeast",
        AREA_PATH + "forest_793.c", "west",
        AREA_PATH + "forest_795.c", "east",
        AREA_PATH + "forest_843.c", "southwest",
        AREA_PATH + "forest_844.c", "south",
        AREA_PATH + "forest_845.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 794 ) );
}

