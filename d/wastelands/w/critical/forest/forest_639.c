/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(639) );
    set_long( get_long_by_id(639) );


    set_exits(({
        AREA_PATH + "forest_588.c", "northwest",
        AREA_PATH + "forest_589.c", "north",
        AREA_PATH + "forest_590.c", "northeast",
        AREA_PATH + "forest_638.c", "west",
        AREA_PATH + "forest_640.c", "east",
        AREA_PATH + "forest_688.c", "southwest",
        AREA_PATH + "forest_689.c", "south",
        AREA_PATH + "forest_690.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 639 ) );
}

