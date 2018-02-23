/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(969) );
    set_long( get_long_by_id(969) );


    set_exits(({
        AREA_PATH + "forest_918.c", "northwest",
        AREA_PATH + "forest_919.c", "north",
        AREA_PATH + "forest_920.c", "northeast",
        AREA_PATH + "forest_968.c", "west",
        AREA_PATH + "forest_970.c", "east",
        AREA_PATH + "forest_1018.c", "southwest",
        AREA_PATH + "forest_1019.c", "south",
        AREA_PATH + "forest_1020.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 969 ) );
}
