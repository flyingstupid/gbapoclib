/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(935) );
    set_long( get_long_by_id(935) );


    set_exits(({
        AREA_PATH + "forest_884.c", "northwest",
        AREA_PATH + "forest_885.c", "north",
        AREA_PATH + "forest_886.c", "northeast",
        AREA_PATH + "forest_934.c", "west",
        AREA_PATH + "forest_936.c", "east",
        AREA_PATH + "forest_984.c", "southwest",
        AREA_PATH + "forest_985.c", "south",
        AREA_PATH + "forest_986.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 935 ) );
}

