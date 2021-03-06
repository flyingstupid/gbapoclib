/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(839) );
    set_long( get_long_by_id(839) );


    set_exits(({
        AREA_PATH + "forest_788.c", "northwest",
        AREA_PATH + "forest_789.c", "north",
        AREA_PATH + "forest_790.c", "northeast",
        AREA_PATH + "forest_838.c", "west",
        AREA_PATH + "forest_840.c", "east",
        AREA_PATH + "forest_888.c", "southwest",
        AREA_PATH + "forest_889.c", "south",
        AREA_PATH + "forest_890.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 839 ) );
}

