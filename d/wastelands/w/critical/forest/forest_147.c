/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(147) );
    set_long( get_long_by_id(147) );


    set_exits(({
        AREA_PATH + "forest_96.c", "northwest",
        AREA_PATH + "forest_97.c", "north",
        AREA_PATH + "forest_98.c", "northeast",
        AREA_PATH + "forest_146.c", "west",
        AREA_PATH + "forest_148.c", "east",
        AREA_PATH + "forest_196.c", "southwest",
        AREA_PATH + "forest_197.c", "south",
        AREA_PATH + "forest_198.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 147 ) );
}

