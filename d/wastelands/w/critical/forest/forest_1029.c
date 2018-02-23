/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(1029) );
    set_long( get_long_by_id(1029) );


    set_exits(({
        AREA_PATH + "forest_978.c", "northwest",
        AREA_PATH + "forest_979.c", "north",
        AREA_PATH + "forest_980.c", "northeast",
        AREA_PATH + "forest_1028.c", "west",
        AREA_PATH + "forest_1030.c", "east",
        AREA_PATH + "forest_1078.c", "southwest",
        AREA_PATH + "forest_1079.c", "south",
        AREA_PATH + "forest_1080.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 1029 ) );
}

