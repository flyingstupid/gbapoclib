/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(140) );
    set_long( get_long_by_id(140) );


    set_exits(({
        AREA_PATH + "forest_89.c", "northwest",
        AREA_PATH + "forest_90.c", "north",
        AREA_PATH + "forest_91.c", "northeast",
        AREA_PATH + "forest_139.c", "west",
        AREA_PATH + "forest_141.c", "east",
        AREA_PATH + "forest_189.c", "southwest",
        AREA_PATH + "forest_190.c", "south",
        AREA_PATH + "forest_191.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 140 ) );
}
