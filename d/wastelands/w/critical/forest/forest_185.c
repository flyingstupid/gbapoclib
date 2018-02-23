/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(185) );
    set_long( get_long_by_id(185) );


    set_exits(({
        AREA_PATH + "forest_134.c", "northwest",
        AREA_PATH + "forest_135.c", "north",
        AREA_PATH + "forest_136.c", "northeast",
        AREA_PATH + "forest_184.c", "west",
        AREA_PATH + "forest_186.c", "east",
        AREA_PATH + "forest_234.c", "southwest",
        AREA_PATH + "forest_235.c", "south",
        AREA_PATH + "forest_236.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 185 ) );
}

