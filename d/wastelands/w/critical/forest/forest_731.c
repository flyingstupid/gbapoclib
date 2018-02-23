/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(731) );
    set_long( get_long_by_id(731) );


    set_exits(({
        AREA_PATH + "forest_680.c", "northwest",
        AREA_PATH + "forest_681.c", "north",
        AREA_PATH + "forest_682.c", "northeast",
        AREA_PATH + "forest_730.c", "west",
        AREA_PATH + "forest_732.c", "east",
        AREA_PATH + "forest_780.c", "southwest",
        AREA_PATH + "forest_781.c", "south",
        AREA_PATH + "forest_782.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 731 ) );
}

