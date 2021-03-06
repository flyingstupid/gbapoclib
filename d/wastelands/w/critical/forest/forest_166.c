/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(166) );
    set_long( get_long_by_id(166) );


    set_exits(({
        AREA_PATH + "forest_115.c", "northwest",
        AREA_PATH + "forest_116.c", "north",
        AREA_PATH + "forest_117.c", "northeast",
        AREA_PATH + "forest_165.c", "west",
        AREA_PATH + "forest_167.c", "east",
        AREA_PATH + "forest_215.c", "southwest",
        AREA_PATH + "forest_216.c", "south",
        AREA_PATH + "forest_217.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 166 ) );
}

