/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(208) );
    set_long( get_long_by_id(208) );


    set_exits(({
        AREA_PATH + "forest_157.c", "northwest",
        AREA_PATH + "forest_158.c", "north",
        AREA_PATH + "forest_159.c", "northeast",
        AREA_PATH + "forest_207.c", "west",
        AREA_PATH + "forest_209.c", "east",
        AREA_PATH + "forest_257.c", "southwest",
        AREA_PATH + "forest_258.c", "south",
        AREA_PATH + "forest_259.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 208 ) );
}

