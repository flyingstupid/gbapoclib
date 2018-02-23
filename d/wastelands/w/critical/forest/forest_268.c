/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(268) );
    set_long( get_long_by_id(268) );


    set_exits(({
        AREA_PATH + "forest_217.c", "northwest",
        AREA_PATH + "forest_218.c", "north",
        AREA_PATH + "forest_219.c", "northeast",
        AREA_PATH + "forest_267.c", "west",
        AREA_PATH + "forest_269.c", "east",
        AREA_PATH + "forest_317.c", "southwest",
        AREA_PATH + "forest_318.c", "south",
        AREA_PATH + "forest_319.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 268 ) );
}

