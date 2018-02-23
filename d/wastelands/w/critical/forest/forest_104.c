/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(104) );
    set_long( get_long_by_id(104) );


    set_exits(({
        AREA_PATH + "forest_53.c", "northwest",
        AREA_PATH + "forest_54.c", "north",
        AREA_PATH + "forest_55.c", "northeast",
        AREA_PATH + "forest_103.c", "west",
        AREA_PATH + "forest_105.c", "east",
        AREA_PATH + "forest_153.c", "southwest",
        AREA_PATH + "forest_154.c", "south",
        AREA_PATH + "forest_155.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 104 ) );
}

