/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(813) );
    set_long( get_long_by_id(813) );


    set_exits(({
        AREA_PATH + "forest_762.c", "northwest",
        AREA_PATH + "forest_763.c", "north",
        AREA_PATH + "forest_764.c", "northeast",
        AREA_PATH + "forest_812.c", "west",
        AREA_PATH + "forest_814.c", "east",
        AREA_PATH + "forest_862.c", "southwest",
        AREA_PATH + "forest_863.c", "south",
        AREA_PATH + "forest_864.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 813 ) );
}

