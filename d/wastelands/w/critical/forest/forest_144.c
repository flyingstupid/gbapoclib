/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(144) );
    set_long( get_long_by_id(144) );


    set_exits(({
        AREA_PATH + "forest_93.c", "northwest",
        AREA_PATH + "forest_94.c", "north",
        AREA_PATH + "forest_95.c", "northeast",
        AREA_PATH + "forest_143.c", "west",
        AREA_PATH + "forest_145.c", "east",
        AREA_PATH + "forest_193.c", "southwest",
        AREA_PATH + "forest_194.c", "south",
        AREA_PATH + "forest_195.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 144 ) );
}

