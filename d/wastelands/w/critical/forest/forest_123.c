/**
 * Area Maker room for forest area
 */
#include <mudlib.h>

inherit ROOM;

#include "base/autogenroom.h"

void reset(status arg) {

    if (arg) return;

    set_weather( 1, 0, 0 );
    set_short( get_short_by_id(123) );
    set_long( get_long_by_id(123) );


    set_exits(({
        AREA_PATH + "forest_72.c", "northwest",
        AREA_PATH + "forest_73.c", "north",
        AREA_PATH + "forest_74.c", "northeast",
        AREA_PATH + "forest_122.c", "west",
        AREA_PATH + "forest_124.c", "east",
        AREA_PATH + "forest_172.c", "southwest",
        AREA_PATH + "forest_173.c", "south",
        AREA_PATH + "forest_174.c", "southeast",
    }));

    set_room_type( get_room_scav_type( "forest", 123 ) );
}

