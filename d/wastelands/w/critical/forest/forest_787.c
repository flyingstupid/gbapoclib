/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(787) );
    set_long( get_long_by_id(787) );


    set_exits(({
        AREA_PATH + "forest_736.c", "northwest",
        AREA_PATH + "forest_737.c", "north",
        AREA_PATH + "forest_738.c", "northeast",
        AREA_PATH + "forest_786.c", "west",
        AREA_PATH + "forest_788.c", "east",
        AREA_PATH + "forest_836.c", "southwest",
        AREA_PATH + "forest_837.c", "south",
        AREA_PATH + "forest_838.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 787 ) );
}

