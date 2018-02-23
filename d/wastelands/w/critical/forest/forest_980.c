/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(980) );
    set_long( get_long_by_id(980) );


    set_exits(({
        AREA_PATH + "forest_929.c", "northwest",
        AREA_PATH + "forest_930.c", "north",
        AREA_PATH + "forest_931.c", "northeast",
        AREA_PATH + "forest_979.c", "west",
        AREA_PATH + "forest_981.c", "east",
        AREA_PATH + "forest_1029.c", "southwest",
        AREA_PATH + "forest_1030.c", "south",
        AREA_PATH + "forest_1031.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 980 ) );
}

