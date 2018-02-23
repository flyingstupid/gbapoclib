/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(174) );
    set_long( get_long_by_id(174) );


    set_exits(({
        AREA_PATH + "forest_123.c", "northwest",
        AREA_PATH + "forest_124.c", "north",
        AREA_PATH + "forest_125.c", "northeast",
        AREA_PATH + "forest_173.c", "west",
        AREA_PATH + "forest_175.c", "east",
        AREA_PATH + "forest_223.c", "southwest",
        AREA_PATH + "forest_224.c", "south",
        AREA_PATH + "forest_225.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 174 ) );
}

